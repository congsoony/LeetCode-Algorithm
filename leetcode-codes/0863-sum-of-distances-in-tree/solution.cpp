#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<vector<int>> v;
    vector<int> count;
    vector<int> res;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        v= vector<vector<int>>(n);
        count = vector<int>(n,1);
        res= vector<int>(n);
        for(vector<int> &e:edges){
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);
        }
        res[0] = dfs();
        dfs2();
        return res;
    }
    int dfs(int cur=0,int h=0,int parent=-1){
        int sum = h;
        for(int next:v[cur]){
            if(next!=parent){
                sum+=dfs(next,h+1,cur);
                count[cur]+=count[next];
            }
        }
        return sum;
    }
    void dfs2(int cur=0,int parent=-1){
        for(int next: v[cur]){
            if(next!=parent){
                res[next]=res[cur]+res.size()-count[next]*2;
                dfs2(next,cur);
            }
        }
    }
};
