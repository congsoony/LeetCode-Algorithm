#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> indegree,parent;
    int n;
    int find(int idx){
        if(parent[idx]==idx)return idx;
        return parent[idx]=find(parent[idx]);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        n = edges.size();
        parent=indegree = vector<int>(n+1);
        vector<int> cand1,cand2;
        for(int i =1;i<=n;i++)parent[i]=i;
        for(vector<int>&e:edges){
            if(indegree[e[1]]!=0){
                cand1 = {indegree[e[1]],e[1]};
                cand2 = e;
            }
            else{
                indegree[e[1]]=e[0];
            }
        }
        for(auto &e :edges){
            if(!cand2.empty()&&e == cand2)continue;
            int u =find(e[0]);
            int v = find(e[1]);
            if(u==v){
                if(!cand1.empty())return cand1;
                return e;
            }
            parent[v]=parent[u];
        }
        return cand2;
    }
};