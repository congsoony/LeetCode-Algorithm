class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int board[101][101] = { 0 };
        
        board[1][1] = !obstacleGrid[0][0];
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1)
                    continue;
                if (obstacleGrid[i - 1][j - 1])
                    continue;
                board[i][j] = board[i - 1][j] + board[i][j - 1];
            }
        }


        return board[n][m];

    }
};
