#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> res;
    map<string,map<string,int>> m;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(vector<string> &t:tickets){
            m[t[0]][t[1]]++;
        }
        
        dfs();
        reverse(res.begin(),res.end());
        //for(string s:res)cout<<s<<" ";
        return res;
    }
    void dfs(string cur="JFK"){

        while(m[cur].size()>0){
            string next = m[cur].begin()->first;
            if(--m[cur][next]==0){
                m[cur].erase(next);
            }
            if(m[cur].size()==0){
                m.erase(cur);
            }
            dfs(next);
        }
        res.push_back(cur);

    }
};