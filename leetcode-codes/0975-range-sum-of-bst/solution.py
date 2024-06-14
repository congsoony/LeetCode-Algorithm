# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rangeSumBST(self, root, low, high):
        if not root: return 0
        sum = root.val if low<=root.val and root.val<=high else 0
        return sum+self.rangeSumBST(root.left,low,high)+self.rangeSumBST(root.right,low,high)

        
