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
	TreeNode *first=nullptr, *second=nullptr;
	TreeNode *before = nullptr;
	void inorder(TreeNode *cur){      
		if (cur->left)
			inorder(cur->left);
		
		if (before != nullptr&&cur->val < before->val){
			if (first == nullptr)
				first = before;
			second = cur;
		}

		before = cur;
		if (cur->right)
			inorder(cur->right);
	}
	void recoverTree(TreeNode* root) {
		if (root == nullptr)
			return;
		inorder(root);
		if (first&&second)
			swap(first->val, second->val);
	}
};
