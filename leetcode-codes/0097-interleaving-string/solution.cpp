class Solution {
public:
string S1,S2,S3;
vector<vector<int>> dp;
bool dfs(int l=0,int r=0){
    if(l+r>=S3.size())return true;
    int &cache = dp[l][r];
    if(cache!=-1)return cache;
    cache = 0;
    if(l<S1.size()&&S1[l]==S3[l+r])
        cache|=dfs(l+1,r);
    if(r<S2.size()&&S2[r]==S3[l+r])
        cache|=dfs(l,r+1);
    return cache;
}
bool isInterleave(string s1, string s2, string s3) {
    tie(S1,S2,S3)={s1,s2,s3};
    dp = vector<vector<int>>(s1.size()+2,vector<int>(s2.size()+2,-1));
    if(s1.size()+s2.size()!=s3.size())return false;
    return dfs();
}
};
