#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> res,check,indegree;
vector<vector<int>> v;
int n;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        n = quiet.size();
        indegree= check = res = vector<int>(n);
        v=vector<vector<int>>(n);
        for(int i =0;i<n;i++)res[i]=i;
        for(vector<int>&r : richer){
            v[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }
        queue<int> q;
        for(int i =0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int cur =q.front();
            q.pop();
            for(int next:v[cur]){
                if(quiet[res[cur]]<quiet[res[next]])res[next]=res[cur];
                if(--indegree[next] == 0)q.push(next);
            }
        }
        return res;
    }
    
};