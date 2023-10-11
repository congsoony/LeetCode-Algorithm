class Solution {
public:
string getPermutation(int n, int k) {
    int f=1;
    vector<int> v;
    for(int i=1;i<n;i++)f*=i;
    for(int i=1;i<=n;i++)v.push_back(i);
    string res;
    k--;
    while(true){
        res+=to_string(v[k/f]);
        v.erase(v.begin()+k/f);
        if(v.size()==0)break;
        k%=f;
        f/=v.size();
    }
    return res;
}

};
