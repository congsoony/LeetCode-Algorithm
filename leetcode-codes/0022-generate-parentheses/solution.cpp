class Solution {
public:
    vector<string> v;
    vector<string> generateParenthesis(int n) {
        dfs(n);
        return v;
    }
    
    
   
bool isform(string &s){
	vector<char> st;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '('){
			st.push_back(s[i]);
		}
		else{
			if (st.empty()){
				return false;
			}
			else{
				st.pop_back();
			}
		}
	}
	if (st.empty())
		return true;
	return false;

}
void dfs(int n,string s="",int idx=0,int close=0){
	if (idx >= 2 * n){
		if (isform(s)){
			v.push_back(s);
		}
		return;
	}
	if (close < n){
		dfs(n,s + "(", idx + 1, close + 1);
	}
	if (close)
		dfs(n,s + ")", idx + 1, close - 1);
}
};
