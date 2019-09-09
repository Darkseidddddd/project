class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    def print_l(self):
        print(self.val, end=' ')
        node = self.next
        while node != None:
            print(node.val)
            node = node.next

def list_length(l):
    n = 0
    while l:
        n += 1
        l = l.next
    return n

def addTwoNumbers(l1,l2):
    res_l = ListNode(0)
    node = res_l
    c = 0
    while l1 or l2:
        sum = 0
        sum += l1.val if l1 else 0
        sum += l2.val if l2 else 0
        sum += c
        c = sum // 10
        sum %= 10
        node.next = ListNode(sum)
        node = node.next
        if l1: l1 = l1.next
        if l2: l2 = l2.next
    if c:
        node.next = ListNode(1)
    return res_l.next

def addTwoNumbers_(l1,l2):
    if list_length(l1) < list_length(l2):
        l1, l2 = l2, l1
    head = l1
    while l1:
        if l2:
            l1.val += l2.val
            l2 = l2.next
        if l1.val // 10:
            l1.val %= 10
            if l1.next:
                l1.next.val += 1
            else:
                l1.next = ListNode(1)
        l1 = l1.next
    return head

if __name__ == '__main__':
    l1 = ListNode(5)
    l1.next = ListNode(8)
    l1.print_l()
    l2 = ListNode(5)
    l = addTwoNumbers_(l1,l2)
    l.print_l()