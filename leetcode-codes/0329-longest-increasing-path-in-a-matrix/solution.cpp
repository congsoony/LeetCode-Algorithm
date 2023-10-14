class Solution {
public:

int dp[200][200];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int n,m;
bool isrange(int y,int x){
    return 0<=y&&y<n&&0<=x&&x<m;
}
int dfs(vector<vector<int>> &matrix,int y,int x){
    int &cache=dp[y][x];
    if(cache!=-1)return cache;
    cache=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(isrange(ny,nx)&&matrix[y][x]<matrix[ny][nx]){
            cache=max(cache,dfs(matrix,ny,nx)+1);
        }
    }
    return cache;
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int res=0;
    n=matrix.size();
    m=matrix[0].size();
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dp[i][j]==-1){
                res=max(res,dfs(matrix,i,j));
            }
        }
    }
    return res;
}
};
