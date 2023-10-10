class Solution {
public:
string S;
set<string> res;
int Max=0;
void dfs(string &s,int idx=0,int garo=0){
    if(garo<0)return;
    if(idx>=s.size()){
        if(garo==0){
            if(Max<S.size()){
                res.clear();
                Max=S.size();
                res.insert(S);
            }
            else if(Max==S.size()){            
               res.insert(S);
            }
        }
        return;
    }
    if(s[idx]=='('||s[idx]==')'){
        S+=s[idx];
        dfs(s,idx+1,garo+(s[idx]=='('?1:-1));
        S.pop_back();
        dfs(s,idx+1,garo);
    }
    else{
        S+=s[idx];
        dfs(s,idx+1,garo);
        S.pop_back();
    }
}
vector<string> removeInvalidParentheses(string s) {
    dfs(s);
    return vector<string>(res.begin(),res.end());
}
};
