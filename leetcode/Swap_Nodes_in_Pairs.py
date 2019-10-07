# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def swapPairs(head):
    l = ListNode(0)
    node = l
    node.next = head
    head = node
    while True:
        l = l.next
        if not l:
            return head.next
        r = l.next
        if not r:
            return head.next
        l.next = r.next
        r.next = l
        node.next = r
        node = l

def printList(l):
    while l:
        print(l.val,end=' ')
        l = l.next
    print('')

def swapPairs_(head):
    if not head or not head.next:
        return head
    node = head.next
    head.next = swapPairs(node.next)
    node.next = head
    return node

if __name__ == '__main__':
    head = ListNode(0)
    node = head
    for i in range(4):
        node.next = ListNode(i+1)
        node = node.next
    head = swapPairs_(head)
    printList(head)