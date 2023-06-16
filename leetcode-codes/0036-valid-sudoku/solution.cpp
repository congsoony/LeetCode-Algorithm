#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int column[10][10]={0};
        int row[10][10]={0};
        int sets[10][10]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                
                int num= board[i][j]-'0';
                if(row[i][num]||column[j][num]||sets[(i/3)*3+j/3][num])return false;
                row[i][num]=1;
                column[j][num]=1;
                sets[(i/3)*3+j/3][num]=1;
            }
        }
        return true;
    }

};
