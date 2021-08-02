#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v = bfs(root);
        vector<vector<int>> res;
        int flag = 1;
        for (int i = 0; i < v.size(); i++) {
            vector<int> v2;
            for (int j = flag==1?0:v[i].size()-1; j < v[i].size()&&j>=0;j+=flag) {
                v2.push_back(v[i][j]);
            }
            flag *= -1;
            if(!v2.empty())
                res.push_back(v2);
        }
        return res;

    }
    vector<vector<int>> bfs(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            int qsize = q.size();
            vector<int> v;
            while (qsize--) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur == NULL) continue;
                v.push_back(cur->val);
                q.push(cur->left);
                q.push(cur->right);
            }
            res.push_back(v);
        }
        return res;
    }
};
