"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def levelOrder(self, root):
        res = []
        q = deque()
        if root:
            q.append(root)
        while q:
            qsize = len(q)
            l = []
            for _ in range(qsize):
                cur = q.popleft()
                l.append(cur.val)
                for next in cur.children:
                    q.append(next)
            res.append(l)
        return res
        
