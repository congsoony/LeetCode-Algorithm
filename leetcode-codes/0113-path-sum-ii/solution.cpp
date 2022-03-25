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
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> res;
	vector<int> v;
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		dfs(root, targetSum);
		return res;
	}
	void dfs(TreeNode* root, int targetSum, int sum = 0) {
		if (!root)return;
		v.push_back(root->val);
		if (!root->left && !root->right && targetSum == sum + root->val)
			res.push_back(v);
		dfs(root->left, targetSum, sum + root->val);
		dfs(root->right, targetSum, sum + root->val);
		v.pop_back();
	}
};
