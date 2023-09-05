class Solution {
public:
vector<vector<int>> dp;
int n,m;
int maximalSquare(vector<vector<char>>& matrix) {
    int res =0;
    n=matrix.size();
    m=matrix[0].size();
    dp = vector<vector<int>>(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='1'){
                dp[i+1][j+1]=min({dp[i][j],dp[i+1][j],dp[i][j+1]})+1;
            }
            res= max(res,dp[i+1][j+1]);
        }
    }
    return res*res;
}

};
