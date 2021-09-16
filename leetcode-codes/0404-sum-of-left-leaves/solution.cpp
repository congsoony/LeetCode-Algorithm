/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return cal(root);
    }
    int cal(TreeNode* root,int flag=false){
        int sum=flag?root->val:0;
        if(root->left||root->right)
            sum=0;
        if(root->left){
            sum+=cal(root->left,true);
        }
        if(root->right)
            sum+=cal(root->right,false);
        return sum;
    }
};
