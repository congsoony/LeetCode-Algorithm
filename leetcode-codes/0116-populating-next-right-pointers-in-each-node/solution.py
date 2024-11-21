"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution(object):
    def connect(self, root):
        if not root: return root
        q = deque()
        q.append(root)        
        while q:
            for i in range(1,len(q)):
                q[i-1].next = q[i]
            qsize = len(q)
            for _ in range(qsize):
                cur = q.popleft()
                if cur.left:
                    q.append(cur.left)
                if cur.right:
                    q.append(cur.right)            
        return root
        
