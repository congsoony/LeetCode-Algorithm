class Solution {
public:
int calculate(string s) {
    if(s[0]!='-')s="+"+s;
    long long res=0;
    int st=0;
    long long num=0;
    vector<pair<int,int>> v;
    int sign=1;
    for(char c:s){
        if(c==' ')continue;
        v.push_back({sign,num});
        if(c=='('){
            v.push_back({2,sign});
            num=0;
            sign=1;
        }
        else if(c==')'){
            int sum=0;
            while(v.back().first!=2){
                sum+=v.back().first*v.back().second;
                v.pop_back();
            }
            
            int sign2 =v.back().second;
            sign=1;
            v.pop_back();
            v.push_back({sign2,sum});
            num=0;
        }
        else if(c=='+'){
            num=0;
            sign=1;
        }
        else if(c=='-'){
            num=0;
            sign=-1;
        }
        else{
            v.pop_back();
            num=num*10+c-'0';
        }
    }
    v.push_back({sign,num});
    while(!v.empty()){
        res+=v.back().first*v.back().second;
        v.pop_back();
    }
    return res;
}
};
