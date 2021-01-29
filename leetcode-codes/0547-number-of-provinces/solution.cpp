int parent[201] = { 0 };
int find(int idx) {
    if (parent[idx] == idx)
        return idx;
    return parent[idx] = find(parent[idx]);
}
void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
    }
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j || isConnected[i][j]==0)
                    continue;
                Union(i, j);
            }
        }
        int visit[201] = { 0 };
        for (int i = 0; i < n; i++) {
            visit[find(i)]=1;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += visit[i];
        }
        return sum;
    }

    
};
