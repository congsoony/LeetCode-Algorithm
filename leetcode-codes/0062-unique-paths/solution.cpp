class Solution {
public:
    int uniquePaths(int m, int n) {
        int board[101][101] = { 0 };
        board[1][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1)
                    continue;
                board[i][j] = board[i][j - 1] + board[i - 1][j];
            }
        }
        return board[m][n];

    }
};
