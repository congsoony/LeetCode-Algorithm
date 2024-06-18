# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def deepestLeavesSum(self, root):
        self.maxh = -1
        self.sum = 0
        self.dfs(root)
        return self.sum
    def dfs(self,root,h=0):
        if not root:
            return
        if self.maxh<h:
            self.maxh=h
            self.sum = root.val
        elif self.maxh == h:
            self.sum+=root.val
        self.dfs(root.left,h+1)
        self.dfs(root.right,h+1)

        
