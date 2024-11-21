# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def getMinimumDifference(self, root):
        l = []
        def dfs(cur):
            if not cur:
                return
            l.append(cur.val)
            dfs(cur.left)
            dfs(cur.right)
        dfs(root)
        l.sort()
        res =int(1e8)
        for i in range(len(l)-1):
            res = min(res,l[i+1]-l[i])
        return res
        
