#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def mergeTwoLists(l1, l2):
    if not l1:
        return l2
    if not l2:
        return l1
    if l1.val > l2.val:
        l1, l2 = l2, l1
    head = l1
    node = head
    l1 = l1.next
    while l1 and l2:
        if l1.val < l2.val:
            l = l1
            l1 = l1.next
        else:
            l = l2
            l2 = l2.next
        node.next = l
        node = node.next
    node.next = l1 if l1 else l2
    return head

def mergeTwoLists_(l1, l2):
    if not l1:
        return l2
    if not l2:
        return l1
    if l1.val < l2.val:
        l1.next = mergeTwoLists(l1.next, l2)
        return l1
    else:
        l2.next = mergeTwoLists(l1, l2.next)
        return l2

def printList(l):
    while l:
        print(l.val, end=' ')
        l = l.next
    print('')

if __name__ == '__main__':
    l1, l2 = ListNode(1), ListNode(1)
    node1, node2 = l1, l2
    for i in range(2,6):
        node1.next = ListNode(i)
        node2.next = ListNode(i)
        node1, node2 = node1.next, node2.next
    printList(l1)
    printList(l2)
    l = mergeTwoLists_(l1,l2)
    printList(l)
    
