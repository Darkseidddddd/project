# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def reverseKGroup(head, k):
    if k == 1 or not head:
        return head
    node = head
    node_list = []
    for i in range(k):
        if not node:
            return head
        node_list.append(node)
        node = node.next
    node_list.append(node)
    node = ListNode(0)
    head = node
    for nd in node_list[-2::-1]:
        node.next = nd
        node = node.next
    head = head.next
    node.next = reverseKGroup(node_list[-1], k)
    return head

def printList(l):
    while l:
        print(l.val, end=' ')
        l = l.next
    print('')

def reverseKGroup_(head, k):
    if k == 1 or not head:
        return head
    stack = []
    node = ListNode(0)
    node.next = head
    head = node
    while True:
        temp1 = temp2 = node.next
        for i in range(k):
            if not temp2:
                node.next = temp1
                return head.next
            stack.append(temp2)
            temp2 = temp2.next
        for i in range(k):
            node.next = stack.pop()
            node = node.next
        node.next = temp2

if __name__ == '__main__':
    k = 3
    head = ListNode(0)
    node = head
    for i in range(10):
        node.next = ListNode(i+1)
        node = node.next
    head = reverseKGroup_(head, k)
    printList(head)