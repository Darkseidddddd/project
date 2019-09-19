import re
def myAtoi(s):
    s = s.strip()
    if len(s) == 0:
        return 0
    symbol = 1
    if s[0] == '-':
            symbol = -1
            s = s[1:]
    elif s[0] == '+':
        s = s[1:]
    if len(s) > 0 and '0' <= s[0] <= '9':
        for i in range(len(s)):
            if s[i] > '9' or s[i] < '0':
                break
            i += 1
        n = int(s[:i])*symbol
        if n > 2**31-1:
            return 2**31-1
        elif n < -2**31:
            return -2**31
        else:
            return n
    return 0

def myAtoi_(s):
    return max(min(int(*re.findall('^[\+\-]?\d+', s.lstrip())), 2**31 - 1), -2**31)

if __name__ == '__main__':
    s = "  -12312"
    print(myAtoi_(s))