class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n,vector<int>(n,0));
        int cnt = 0;
        int y = -1, x = -1;
        while (cnt < n * n) {
            for (y++, x++; x < n && !arr[y][x]; x++)
                arr[y][x] = ++cnt;
            for (y++, x--; y < n && !arr[y][x]; y++)
                arr[y][x] = ++cnt;
            for (y--, x--; x >= 0 && !arr[y][x]; x--)
                arr[y][x] = ++cnt;
            for (y--, x++; y >= 0 && !arr[y][x]; y--)
                arr[y][x] = ++cnt;
        }
        return arr;
    }
};
