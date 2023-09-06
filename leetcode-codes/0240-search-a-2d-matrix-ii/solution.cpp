class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m = matrix[0].size();
    int y=-1,x=-1;
    vector<int> rv,cv;
    for(int i=0;i<n;i++){
        int idx = lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
        if(idx<m&&matrix[i][idx]==target){
            return true;
        }
    }
    return false;
}
};
