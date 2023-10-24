# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def partition(self, head, x):
        l = [] 
        l2 = []
        h = head

        while h:
            if h.val<x:
                l.append(h.val)
            else :
                l2.append(h.val)
            h=h.next
        ret = None
        tail = None
        for i in l:
            if ret==None:
                ret = ListNode(i)
                tail=ret
            else :
                tail.next=ListNode(i)
                tail=tail.next
        for i in l2:
            if ret==None:
                ret = ListNode(i)
                tail=ret
            else :
                tail.next=ListNode(i)
                tail=tail.next
        return ret
