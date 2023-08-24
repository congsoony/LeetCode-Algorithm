class Solution {
public:
int check[10][10];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int n,m,length;
string s;
bool isrange(int y,int x){
    return 0<=y&&y<n&&0<=x&&x<m;
}
bool dfs(int y,int x,string &word,vector<vector<char>>& board){
    if(s.size()>=length) return s==word;
    bool flag = false;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(isrange(ny,nx)&&check[ny][nx]==0){
            check[ny][nx]=1;
            s.push_back(board[ny][nx]);
            flag|=dfs(ny,nx,word,board);
            check[ny][nx]=0;
            s.pop_back();
        }
    }
    return flag;
}
bool exist(vector<vector<char>>& board, string word) { 
    length = word.size();
    n=board.size();
    m=board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0]){
                check[i][j]=1;
                s.push_back(board[i][j]);
                if(dfs(i,j,word,board)) return true;
                check[i][j]=0;
                s.pop_back();
            }
        }
    }
    return false;
}
};
