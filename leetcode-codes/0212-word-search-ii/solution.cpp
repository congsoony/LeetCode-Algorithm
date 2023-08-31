class Solution {
public:
int h =0;
unordered_set<string> word;
vector<string> res;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int check[13][13];
int n,m;
string d;
bool isrange(int y,int x){
    return 0<=y&&y<n&&0<=x&&x<m;
}
void dfs(vector<vector<char>> &board,int y,int x){
    if(word.count(d)){
        res.push_back(d);
        word.erase(d);
    }
    if(d.size()>=h)return;
    for(int i=0;i<4;i++){
        int ny =y+dy[i];
        int nx=x+dx[i];
        if(isrange(ny,nx)&&check[ny][nx]==0){
            d+=board[ny][nx];
            check[ny][nx]=1;
            dfs(board,ny,nx);
            d.pop_back();
            check[ny][nx]=0;
        }
    }
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    for(string &s : words){
        word.insert(s);
        h=max(h,(int)s.size());
    }
    n=board.size();
    m=board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            check[i][j]=1;
            d+=board[i][j];
            dfs(board,i,j);
            d.pop_back();
            check[i][j]=0;
        }
    }
    return res;
}
};
