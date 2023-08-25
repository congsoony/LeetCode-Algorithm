class Solution {
public:
vector<vector<int>> dp;
int dfs(string &s,string &t,int l=0,int r=0){
    if(r>=t.size())return 1;
    if(l>=s.size())return 0;
    int &cache = dp[l][r];
    if(cache !=-1)return cache;
    cache = 0;
    if(s[l]==t[r])
       cache+=dfs(s,t,l+1,r+1);
    cache+=dfs(s,t,l+1,r);
    return cache;
}

int numDistinct(string s, string t) {
    dp = vector<vector<int>>(s.size(),vector<int>(t.size(),-1));
    return dfs(s,t);
}
};
