//By 콩순이냉장고
#include<bits/stdc++.h>
using namespace std;class Solution {
public:
    vector<int> dp;
    int dfs(string &s,set<string> &m,int cur){
        int &cache = dp[cur];
        if(cur>=s.size())return true;
        if(cache!=-1)return cache;
        for(int i=cur;i<s.size();i++){
            if(m.count(s.substr(cur,i-cur+1)) &&dfs(s,m,i+1)){
                return cache = true;
            }
        }
        return cache = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> m (wordDict.begin(),wordDict.end());
        dp = vector<int>(s.size(),-1);
        return dfs(s,m,0);
    }
};
