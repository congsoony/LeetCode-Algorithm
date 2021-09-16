#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> v[20000];
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res, indegree(n);
        for (vector<int>& t : edges) {
            v[t[0]].push_back(t[1]);
            v[t[1]].push_back(t[0]);
            indegree[t[0]]++;
            indegree[t[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 1)q.push(i);
        while (!q.empty()) {
            int qsize = q.size();
            res.clear();
            while (qsize--) {
                int cur = q.front();
                res.push_back(cur);
                q.pop();
                for (int next : v[cur]) {
                    indegree[next]--;
                    if (indegree[next] == 1)
                        q.push(next);
                }
            }
        }
        if (res.empty())return{ 0 };
        return res;
    }

};
