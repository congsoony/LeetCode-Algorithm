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
    public List<TreeNode> generateTrees(int n) {
        if(n==0)return new ArrayList<>();
        return makeBST(1,n);
    }
    public List<TreeNode> makeBST(int s,int e){
        List<TreeNode> list = new ArrayList<>();
        if(s>e){
            list.add(null);
            return list;
        }
        for(int i=s;i<=e;i++){
            List<TreeNode> l = makeBST(s,i-1);
            List<TreeNode> r = makeBST(i+1,e);
            for(TreeNode left : l){
                for(TreeNode right : r){
                    TreeNode root = new TreeNode(i);
                    root.left = left;
                    root.right = right;
                    list.add(root);
                }
            }
        }
        return list;
    }
}