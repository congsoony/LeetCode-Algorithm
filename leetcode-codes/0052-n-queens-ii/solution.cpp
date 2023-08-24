class Solution {
public:
int column[30];
int rup[30];
int lup[30];
vector<vector<string>> v;
int check[30][30];
int dfs(int i,int n){
    if(i>=n){
        return 1;
    }
    int sum=0;
    for(int j=0;j<n;j++){
        if(column[j]==0&&rup[n+i+j]==0&&lup[n+i-j]==0){
            column[j]=rup[n+i+j]=lup[n+i-j]=check[i][j]=1;
            sum+=dfs(i+1,n);
            column[j]=rup[n+i+j]=lup[n+i-j]=check[i][j]=0;            
        }
    }
    return sum;
}
    int totalNQueens(int n) {
        return dfs(0,n);
    }
};
