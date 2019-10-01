#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def printVal(head):
    while head:
        print(head.val, end=' ')
        head = head.next
    print('')

def removeNthFromEnd(head, n):
    node = []
    head_ = head
    while head_:
        node.append(head_)
        head_ = head_.next
    length = len(node)
    if length-n:
        node[length-n-1].next = node[length-n-1].next.next
    else:
        head = head.next
    return head

if __name__ == '__main__':
    head = ListNode(0)
    head_ = head
    for i in range(1,10):
        temp = ListNode(i)
        head_.next = temp
        head_ = head_.next
    n = 10
    printVal(head)
    head = removeNthFromEnd(head, n)
    printVal(head)