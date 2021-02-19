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
	int depth = 0;
	int value = 0;
	int findBottomLeftValue(TreeNode* root) {
		depth = 0;
		value = 0;
		VRL(root);
		return value;
	}
	void VRL(TreeNode *root ,int height=0) {
		if (depth <= height) {
			depth = height;
			value = root->val;
		}
		if (root->right)
			VRL(root->right, height + 1);
		if (root->left)
			VRL(root->left, height + 1);
	}
};
