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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root,"",res);
        return res;
    }
    void dfs(TreeNode* root,string s,vector<string> &res){
        if(!root->left&&!root->right){
            res.push_back(s+to_string(root->val));
            return;
        }
        if(root->left)
            dfs(root->left,s+to_string(root->val)+"->",res);
        if(root->right)
            dfs(root->right,s+to_string(root->val)+"->",res);
    }
};
