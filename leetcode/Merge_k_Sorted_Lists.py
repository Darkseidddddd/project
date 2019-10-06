# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def insertLists(l, node):
    if not node:
        return
    for i in range(len(l)):
        if node.val > l[i].val:
            l.insert(i,node)
            break
    else:
        l.append(node)
def mergeKLists(lists):
    l = []
    for node in lists:
        insertLists(l, node)
    if not l:
        return None
    head = l.pop()
    insertLists(l, head.next)
    node = head
    while l:
        node.next = l.pop()
        node = node.next
        #print(node.val, end=' ')
        insertLists(l, node.next)
    return head

def printList(head):
    while head:
        print(head.val, end=' ')
        head = head.next
    print('')

def mergeKLists_(lists):
        l = []
        for node in lists:
            while node:
                l.append(node.val)
                node = node.next
        if not l:
            return None
        l.sort()
        head = ListNode(0)
        node = head
        for i in l:
            node.next = ListNode(i)
            node = node.next
        node.next = None
        return head.next

if __name__ == '__main__':
    head = ListNode(1)
    head.next = ListNode(4)
    head.next.next = ListNode(5)
    l = []
    l.append(head)
    head = ListNode(1)
    head.next = ListNode(3)
    head.next.next = ListNode(4)
    l.append(head)
    head = ListNode(2)
    head.next = ListNode(6)
    l.append(head)
    head = mergeKLists_(l)
    printList(head)