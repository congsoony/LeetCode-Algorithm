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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return post(nullptr,preorder,inorder,0,preorder.size());
    }
    TreeNode* post(TreeNode * root,vector<int>& preorder, vector<int>& inorder,int s,int e,int pos=0){
        root=nullptr;
        for(int i =s;i<e;i++){
            if(preorder[pos]==inorder[i]){
                root=new TreeNode(inorder[i]);
                root->left = post(root->left,preorder,inorder,s,i,pos+1);
                root->right = post(root->right,preorder,inorder,i+1,e,pos+i+1-s);
            }
        }
        return root;
    }
};
