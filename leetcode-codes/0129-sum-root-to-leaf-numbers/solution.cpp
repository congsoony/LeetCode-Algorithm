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
long long dfs(TreeNode*cur,long long num=0){
    if(cur->left==nullptr&&cur->right==nullptr){
        return num*10+cur->val;
    }
    long long sum=0;
    if(cur->left)
        sum+=dfs(cur->left,num*10+cur->val);
    if(cur->right)
        sum+=dfs(cur->right,num*10+cur->val);
    return sum;
}
int sumNumbers(TreeNode* root) {
    return dfs(root);
}
};
