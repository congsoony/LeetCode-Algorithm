#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dy[4]={-1,0,1,0};
    int dx[4]={0,1,0,-1};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<char>> Board(n+2,vector<char>(m+2,'O'));
        vector<vector<int>> check(n+2,vector<int>(m+2));
        
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                Board[i][j]=board[i-1][j-1];
            }
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        check[0][0]=1;
        while(!q.empty()){
            int y,x;
            tie(y,x)=q.front();
            q.pop();
            for(int i =0;i<4;i++){
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(0<=ny&&ny<=n+1&&0<=nx&&nx<=m+1 && Board[ny][nx]=='O'&&check[ny][nx]==0){
                    check[ny][nx]=1;
                    q.push({ny,nx});
                }
            }
        }

        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(Board[i][j]=='O' &&check[i][j]==0){
                    board[i-1][j-1]='X';
                }
            }
        }
    }
    
};