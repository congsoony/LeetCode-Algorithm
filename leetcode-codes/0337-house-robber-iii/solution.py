# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rob(self, root):
        dp = Counter()
        def dfs(cur,t):
            if not cur:return 0
            if dp[(cur,t)]!=0:
                return dp[(cur,t)]
            res = 0
            if t==0:
                res =dfs(cur.left,1)+dfs(cur.right,1)+cur.val
            res = max(dfs(cur.left,0)+dfs(cur.right,0),res)
            dp[(cur,t)]=res
            return res
        return dfs(root,0)
