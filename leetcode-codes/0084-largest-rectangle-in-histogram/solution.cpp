class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
    int ret = 0;
    heights.push_back(0);
    vector<int> st;
    for(int i=0;i<heights.size();i++){
        while(!st.empty()&&heights[st.back()]>=heights[i]){
            int j = st.back();
            st.pop_back();
            int width = st.empty()?i:i-st.back()-1;
            ret = max(ret,width*heights[j]);
        }
        st.push_back(i);
    }
    return ret;
}
};
