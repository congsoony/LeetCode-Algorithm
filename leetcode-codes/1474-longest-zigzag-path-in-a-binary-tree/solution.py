# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def longestZigZag(self, root):
        
        self.res = 0
        def dfs(tree,before,len=0):
            if not tree:
                return
            self.res = max(self.res,len)
            if before==0:
                dfs(tree.right,1,len+1)
                dfs(tree.left,0,1)
            else:
                dfs(tree.left,0,len+1)
                dfs(tree.right,1,1)
        
        dfs(root,1)
        dfs(root,0)

        return self.res

        


