class Solution {
public:
int getRect(vector<int>&v){
    vector<int> st;
    int res=0;
    for(int i=0;i<v.size();i++){
        while(!st.empty()&&v[st.back()]>=v[i]){
            int j =st.back();
            st.pop_back();
            int width=st.empty()?i:i-st.back()-1;
            res = max(res,width*v[j]);
        }
        st.push_back(i);
    }

    return res;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int n=matrix.size();
    int m = matrix[0].size();
    vector<int> v(m+1);
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[j]+=(matrix[i][j]=='1'?1:-v[j]);
        }
        res=max(res,getRect(v));
    }
    return res;
}
};
