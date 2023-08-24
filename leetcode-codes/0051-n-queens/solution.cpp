class Solution {
public:
int column[30];
int rup[30];
int lup[30];
vector<vector<string>> v;
int check[30][30];
void dfs(int i,int n){
    if(i>=n){
        vector<string> s(n,string(n,'.'));
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                if(check[y][x])
                    s[y][x]='Q';
            }
        }
        v.push_back(s);
        return;
    }
    for(int j=0;j<n;j++){
        if(column[j]==0&&rup[n+i+j]==0&&lup[n+i-j]==0){
            column[j]=rup[n+i+j]=lup[n+i-j]=check[i][j]=1;
            dfs(i+1,n);
            column[j]=rup[n+i+j]=lup[n+i-j]=check[i][j]=0;            
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {   
        dfs(0,n);
        return v;
    }
};
