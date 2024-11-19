# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        return self.pre(root)!=-1
    def pre(self,tree):
            if not tree:
                return 0
            l = self.pre(tree.left)
            r = self.pre(tree.right)

            if l==-1 or r==-1:
                 return -1
            if abs(l-r)>1 :return -1
            return max(l,r)+1
    
