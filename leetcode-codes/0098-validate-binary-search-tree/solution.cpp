class Solution {
public:
	bool isValidBST(TreeNode* root) {
		bool flag = true;
		dfs(flag, root,0,0);
		return flag;
	}
	void dfs(bool &flag, TreeNode * tree,int low,int high){
		if (tree == NULL)
			return;
		if (tree->left){
			if (tree->left->val >= tree->val){
				flag = false;
				return;
			}
			if (low&&tree->left->val <= low){
				flag = false;
				return;
			}
		}
		if (tree->right){
			if (tree->right->val <= tree->val){
				flag = false;
				return;
			}
			if (high&&tree->right->val>= high){
				flag = false;
				return;
			}
		}
		dfs(flag, tree->left,low,tree->val);
		dfs(flag, tree->right,tree->val,high);
	}
	void print(TreeNode* root)
	{
		if (root == NULL)
			return;
		cout << root->val << endl;
		print(root->left);
		print(root->right);
	}
};
