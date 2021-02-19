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
	vector<int> tree;
	int maxheight;
	vector<int> largestValues(TreeNode* root) {
		vector<int> res;
		if (!root)
			return res;
		maxheight = 0;
		tree.clear();
		tree.resize(4000, INT_MIN);

		PreOrder(root);
		for (int i = 0; i <= maxheight; i++)
			res.push_back(tree[i]);
		return res;
	}
	void PreOrder(TreeNode* root, int height=0) {
		if (tree[height] <= root->val) {
			tree[height] = root->val;
			maxheight = max(maxheight, height);
		}
		if (root->left)
			PreOrder(root->left, height + 1);
		if (root->right)
			PreOrder(root->right, height + 1);
	}
};
