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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return false;
        return dfs(root,targetSum);
    }
    bool dfs(TreeNode* root, int targetSum,int sum=0){
        if(!root->left&&!root->right){
            return sum+root->val==targetSum;
        }
        bool flag=false;
        if(root->left)
            flag|=dfs(root->left,targetSum,sum+root->val);
        if(root->right)
            flag|=dfs(root->right,targetSum,sum+root->val);
        return flag;
    }
};
