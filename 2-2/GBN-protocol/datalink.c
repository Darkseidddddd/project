#include <stdio.h>
#include <string.h>

#include "protocol.h"
#include "datalink.h"

#define DATA_TIMER  4500
#define wsize 63

struct FRAME {  
    unsigned char kind; /* FRAME_DATA */
    unsigned char ack;
    unsigned char seq;
    unsigned char data[PKT_LEN]; 
    unsigned int  padding;
};


static unsigned char buffer[wsize+1][PKT_LEN];
static unsigned char frame_total[wsize+1];
static unsigned int frame_expected = 0;
static int phl_ready = 0, window_start = 0, window_end = -1, frame_to_send = 0, begin = 1, rewindow_end = -1;

void frame_total_init()
{
	unsigned char i = 0;
	while (i < wsize+1) {
		frame_total[i] = i;
		i++;
	}
}

void inc_window_end()
{	
	if (rewindow_end == -1)
		rewindow_end = window_start;
	else
		rewindow_end = (rewindow_end + 1) % (wsize + 1);
}

void inc_window_start()
{
	window_start = (window_start + 1) % (wsize + 1);
}

void inc_frame_expected()
{
	frame_expected = (frame_expected + 1) % (wsize + 1);
}

int dif_value()
{
	if (window_end == -1)
		return 0;
	if (window_end >= window_start)
		return window_end - window_start + 1;
	else
		return window_end + wsize - window_start + 2;
}

void stop(int ack)
{
	//lprintf("start\n");
	if (ack >= window_start) {
		while (ack >= window_start) {
			stop_timer(ack);
			ack--;
		}
	} else {
		while (ack >= 0) {
			stop_timer(ack);
			ack--;
		}
		ack = wsize;
		while (ack >= window_start) {
			stop_timer(ack);
			ack--;
		}
	}
	//lprintf("end\n");
}

int is_between(unsigned char ack)
{
	if (window_end >= window_start) {
		if (ack >= window_start && ack <= window_end)
			return 1;
	} else if (ack <= window_end || ack >= window_start)
		return 1;
	return 0;
}

static void put_frame(unsigned char *frame, int len)
{
    *(unsigned int *)(frame + len) = crc32(frame, len);
    send_frame(frame, len + 4);
    phl_ready = 0;
}

static void send_data_frame(void)
{
    struct FRAME s;

    s.kind = FRAME_DATA;
    s.seq = frame_total[frame_to_send];
	if (frame_expected == 0)
		s.ack = wsize;
	else
		s.ack = frame_expected - 1;
    memcpy(s.data, buffer[rewindow_end], PKT_LEN);

    dbg_frame("Send DATA %d %d, ID %d\n", s.seq, s.ack, *(short *)s.data);

    put_frame((unsigned char *)&s, 3 + PKT_LEN);
    start_timer(s.seq, DATA_TIMER);
}

int main(int argc, char **argv)
{
    int event, arg;
    struct FRAME f;
	int len = 0, temp;
	frame_total_init();

    protocol_init(argc, argv); 
    lprintf("Designed by yu, build: " __DATE__"  "__TIME__"\n");

    disable_network_layer();

    for (;;) {
        event = wait_for_event(&arg);

        switch (event) {
        case NETWORK_LAYER_READY:			//正常传
			temp = rewindow_end;
			inc_window_end();
			if (temp == window_end) {
				get_packet(buffer[rewindow_end]);
				window_end = rewindow_end;
			}
			frame_to_send = rewindow_end;
            send_data_frame();
            break;

        case PHYSICAL_LAYER_READY:
            phl_ready = 1;
            break;

        case FRAME_RECEIVED: 
            len = recv_frame((unsigned char *)&f, sizeof f);
            if (len < 5 || crc32((unsigned char *)&f, len) != 0) {
                dbg_event("**** Receiver Error, Bad CRC Checksum\n");
                break;
            }
            dbg_frame("Recv DATA %d %d, ID %d\n", f.seq, f.ack, *(short *)f.data);
            if (f.seq == frame_total[frame_expected]) {
                put_packet(f.data, len - 7);
				inc_frame_expected();
            }
			if (is_between(f.ack)) {
				stop(f.ack);
				if (f.ack == window_end) {
					window_end = -1;
					rewindow_end = -1;
				}
				window_start = (f.ack + 1) % (wsize + 1);
				//lprintf("w_start = %d, w_end = %d\n", window_start, window_end);
            }
            break; 
			
        case DATA_TIMEOUT:					//超时重传
            dbg_event("---- DATA %d timeout\n", arg);
			stop(window_end);
			rewindow_end = -1;
			frame_to_send = window_start;
			phl_ready = 1;
            break;
        }

		if (dif_value() < wsize && phl_ready) {
			enable_network_layer();
		} else
            disable_network_layer();
    }
}
