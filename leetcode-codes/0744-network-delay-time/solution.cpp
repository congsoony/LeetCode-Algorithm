//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
#define v vector
#define vi v<int>
#define vvi v<vi>
class Solution {
public:
    vvi w;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        w = vvi(n + 1, vi(n + 1, 1e8));
        for (vector<int> t : times) 
            w[t[0]][t[1]] = t[2];
        return floyd(n, k);
    }
    int floyd(int n, int start) {
        for (int i = 1; i <= n; i++)
            w[i][i] = 0;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
                }
            }
        }
        int Max = 0;
        for (int i = 1; i <= n; i++)
            Max = max(Max, w[start][i]);
        return Max == 1e8 ? -1 : Max;
    }
};
