class Solution {
public:
vector<string> res;
string s;
void dfs(string &num,int target,long long before,long long sum,int idx){
    if(idx>=num.size()){
        if(sum==target){
            res.push_back(s);
        }
        return;
    }
    for(int i=idx;i<num.size();i++){
        string temp =num.substr(idx,i-idx+1);
        if(temp.size()>1&&temp[0]=='0')break;
        long long number = stoll(temp);
        s+='+';
        s+=temp;
        dfs(num,target,number,sum+number,i+1);
        s[s.size()-temp.size()-1]='-';
        dfs(num,target,-number,sum-number,i+1);
        s[s.size()-temp.size()-1]='*';
        dfs(num,target,before*number,sum-before+before*number,i+1);
        s.erase(s.begin()+s.size()-temp.size()-1,s.end());
    }

}
vector<string> addOperators(string num, int target) {
    for(int i=0;i<num.size();i++){
        string temp=num.substr(0,i+1);
        if(temp.size()>1&&temp[0]=='0')break;
        long long number = stoll(temp);
        s+=temp;
        dfs(num,target,number,number,i+1);
        for(int j=0;j<temp.size();j++)s.pop_back();
    }
    return res;
}
};
