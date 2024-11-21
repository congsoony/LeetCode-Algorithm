class Solution(object):
    def addOneRow(self, root, val, depth):
        def dfs(cur,h=1):
            if not cur: return
            if h==depth-1:
                left = cur.left
                right = cur.right
                cur.left=TreeNode(val)
                cur.right = TreeNode(val)
                cur.left.left = left
                cur.right.right=right
                return
            dfs(cur.left,h+1)
            dfs(cur.right,h+1)
        if depth >1:
            dfs(root,1)
        else :
            newtree = TreeNode(val)
            newtree.left = root
            root=newtree

        return root
