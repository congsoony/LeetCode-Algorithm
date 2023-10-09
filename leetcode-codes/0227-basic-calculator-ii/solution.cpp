class Solution {
public:
int calculate(string s) {
    stringstream ss("+"+s);
    int res=0;
    vector<int> st;
    int n;
    char op;

    while(ss>>op>>n){
        if(op=='+'||op=='-'){
            st.push_back(op=='+'?n:-n);
        }
        else{
            int t= st.back();
            st.pop_back();
            st.push_back(op=='*'?t*n:t/n);
        }
    }
    while(!st.empty()){
        res+=st.back();
        st.pop_back();
    }
    return res;
}
};
