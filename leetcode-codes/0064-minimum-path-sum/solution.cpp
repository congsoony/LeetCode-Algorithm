class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int board[200][200] = { 0 };
        board[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
            board[i][0] = grid[i][0]+board[i-1][0];
        for (int i = 1; i < m; i++)
            board[0][i] = grid[0][i]+board[0][i-1];

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++) {
                board[i][j] = min(board[i][j - 1], board[i - 1][j]) + grid[i][j];
            }
        }
        return board[n-1][m-1];
    }
};
