/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        Queue<Object[]> q =new LinkedList<>();
        q.add(new Object[]{root,1});
        int res = 0;
        while(!q.isEmpty()){
            int size = q.size();
            int l =(int)1e9,r=0;
            for(int i =0;i<size;i++){
                Object[] o = q.poll();
                TreeNode cur = (TreeNode)o[0];
                Integer node = (Integer)o[1];
                if(i==0)
                    l=node;
                if(i==size-1)
                    r=node;
                if(cur.left !=null){
                    q.add(new Object[]{cur.left,node*2});
                }
                if(cur.right!=null){
                    q.add(new Object[]{cur.right,node*2+1});
                }
            }
            res = Math.max(res,r-l+1);
        }
        return res;
    }
}