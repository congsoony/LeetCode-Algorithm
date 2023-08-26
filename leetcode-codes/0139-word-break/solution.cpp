class Solution {
public:
vector<int> dp;
int dfs(string &s,set<string> &m,int idx=0){
    if(idx>=s.size()) return true;

    int &cache = dp[idx];
    if(cache!=-1)return cache;
    cache = 0;
    for(int i=idx;i<s.size();i++){
        if(m.count(s.substr(idx,i+1-idx))&&dfs(s,m,i+1)){
            return cache=true;
        }
    }
    return cache;
}
bool wordBreak(string s, vector<string>& wordDict) {
    set<string> m(wordDict.begin(),wordDict.end());
    dp = vector<int>(s.size(),-1);
    return dfs(s,m);
}
};
