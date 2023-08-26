class Solution {
public:
vector<string> v;
void dfs(string s,set<string>&m,string res=""){
    if(s.size()==0){
        res.pop_back();
        v.push_back(res);
        return;
    }
    for(int i=0;i<s.size();i++){
        string t = s.substr(0,i+1);
        if(m.count(t)){
            dfs(s.substr(i+1),m,res+t+" ");
        }
    }
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
    set<string> m(wordDict.begin(),wordDict.end());
    dfs(s,m);
    return v;
}
};
