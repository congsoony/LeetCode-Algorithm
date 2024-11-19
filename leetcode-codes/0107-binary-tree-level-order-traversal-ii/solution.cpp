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
//By 콩순이냉장고
#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()){
            int qsize =q.size();
            vector<int> v;
            while(qsize--){
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            res.push_back(v);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
