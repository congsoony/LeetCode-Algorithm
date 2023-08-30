class Solution {
public:
vector<vector<int>>check,row,col,Board;
void dfs(vector<vector<char>>& board,int cnt=0) {
    if(cnt>=81){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                board[i][j]=Board[i][j]+1+'0';
                cout<<Board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    int y=(cnt / 9);
    int x= cnt %9;

    if(Board[y][x]!=-1){
        dfs(board,cnt+1);
        return;
    }
    for(int num=0;num<9;num++){
        int y2 = (y/3)*3;
        int x2 = x/3;
        if(check[y2+x2][num]==-1&&row[y][num]==-1&&col[x][num]==-1){
            check[y2+x2][num]=row[y][num]=col[x][num]=1;
            Board[y][x]=num;
            dfs(board,cnt+1);
            check[y2+x2][num]=row[y][num]=col[x][num]=-1;
            Board[y][x]=-1;
        }
    }
}

void solveSudoku(vector<vector<char>>& board,int idx=0) {
    Board = check = row = col=vector<vector<int>>(10,vector<int>(10,-1));
    int cnt =81;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            Board[i][j]=(board[i][j]=='.'?-1:board[i][j]-'0'-1);
            if(Board[i][j]!=-1){
                int y =(i/3)*3;
                int x = j/3;
                int num = Board[i][j];
                check[y+x][num]=1;
                row[i][num]=1;
                col[j][num]=1;
                cnt--;
            }
        }
    }
    dfs(board);
}

};
