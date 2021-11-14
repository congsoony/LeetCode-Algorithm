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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int,int> m;
        m[0]=1;
        return dfs(root,targetSum,m);
    }
    int dfs(TreeNode *root, int targetSum,unordered_map<int,int>&m,int sum=0){
        if(!root) return 0;
        sum+=root->val;
        int total=m[sum-targetSum];
        
        m[sum]++;
        total+=dfs(root->left,targetSum,m,sum)+dfs(root->right,targetSum,m,sum);
        m[sum]--;
        return total;
    }
};
