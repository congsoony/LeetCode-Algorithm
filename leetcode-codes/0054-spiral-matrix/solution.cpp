class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> arr(n,vector<int>(m));
        vector<pair<int,int>> v;
        vector<int> res;
        int cnt =1;
        int y=-1,x=-1;
        while(cnt<=n*m){
            for(y++,x++;0<=y&&y<n&&0<=x&&x<m&&arr[y][x]==0;){
                arr[y][x]=cnt++;
                v.push_back({y,x++});
            }
            for(y++,x--;0<=y&&y<n&&0<=x&&x<m&&arr[y][x]==0;){
                arr[y][x]=cnt++;
                v.push_back({y++,x});
            }
            for(y--,x--;0<=y&&y<n&&0<=x&&x<m&&arr[y][x]==0;){
                arr[y][x]=cnt++;
                v.push_back({y,x--});
            }
            for(y--,x++;0<=y&&y<n&&0<=x&&x<m&&arr[y][x]==0;){
                arr[y][x]=cnt++;
                v.push_back({y--,x});
            }
        }
        for(auto [i,j]:v){
            res.push_back(matrix[i][j]);
        }
        return res;
    }
};
