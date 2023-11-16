# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        l=[]
        q = deque()
        if root: q.append(root)
        while q:
            qsize=len(q)
            l.append(q[-1].val)
            while qsize:
                qsize-=1
                cur = q.popleft()
                if cur.left:q.append(cur.left)
                if cur.right:q.append(cur.right)
        return l
