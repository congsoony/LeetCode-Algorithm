class Solution {
public:
   vector<int> dp;
int rec(int val){
    if(val==0)return 0;
    if(dp[val]!=-1)return dp[val];
    int res = 1e8;
    for(int i=1;i*i<=val;i++){
        res = min(res,1+rec(val-i*i));
    }
    return dp[val]=res;
}
 int numSquares(int n) {
    dp=vector<int>(n+1,-1);
    return rec(n);
}
};
