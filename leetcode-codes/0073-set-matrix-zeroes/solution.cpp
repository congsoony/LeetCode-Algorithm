
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:

    int column[200];
    int row[200];
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> res = matrix;
        int n = matrix.size();
        int m = matrix[0].size();
        memset(row, 0, sizeof(row));
        memset(column, 0, sizeof(column));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!matrix[i][j]) {
                    if (!row[i]) {
                        setRowZero(res, m, i);
                        row[i] = 1;
                    }
                    if (!column[j]) {
                        setColumnZero(res, n, j);
                        column[j] = 1;
                    }
                }
            }
        }
        matrix = res;
    }
    void setRowZero(vector<vector<int>>& matrix, int m, int r) {
        for (int i = 0; i < m; i++)
            matrix[r][i] = 0;
    }
    void setColumnZero(vector<vector<int>>& matrix, int n, int c) {
        for (int i = 0; i < n; i++) {
            matrix[i][c] = 0;
        }
    }
};
