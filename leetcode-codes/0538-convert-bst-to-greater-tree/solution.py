# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def convertBST(self, root):
        def dfs(node):
            if not node:
                return 0
            res = node.val + dfs(node.left)+dfs(node.right)
            return res
        self.total = dfs(root)
        def inorder(node):
            if not node:
                return
            inorder(node.left)
            t  = node.val
            node.val = self.total
            self.total-=t
            inorder(node.right)
        inorder(root)

        return root
        
