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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (root->val == subRoot->val) {
            return sametree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool sametree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (root->val != subRoot->val) return false;
        if (!sameShape(root, subRoot)) return false;
        return sametree(root->left, subRoot->left) && sametree(root->right, subRoot->right);
    }
    bool sameShape(TreeNode* root, TreeNode* subRoot) {
        int l = 0, r = 0;
        l |= root->left ? 1 : 0;
        l |= root->right ? 2 : 0;
        r |= subRoot->left ? 1 : 0;
        r |= subRoot->right ? 2 : 0;
        return l == r;
    }

};
