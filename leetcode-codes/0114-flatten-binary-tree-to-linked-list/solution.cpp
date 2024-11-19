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
    vector<TreeNode*> v;
    void flatten(TreeNode* root) {
        pre(root);
        for (int i = 1; i < v.size(); i++) {
            root->left = NULL;
            root->right = new TreeNode(v[i]->val);
            root = root->right;
            root->left = NULL;
        }
    }
    void pre(TreeNode* root) {
        if (!root)return;
        v.push_back(root);
        pre(root->left);
        pre(root->right);
    }
};
