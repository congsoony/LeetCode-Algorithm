class Solution {
public:
vector<string> restoreIpAddresses(string s) {
    vector<string> v;
    for(int i=0;i<81;i++){
        int temp=i;
        int length=0;
        vector<int> t;
        for(int j=0;j<4;j++){
            t.push_back(temp%3+1);
            length+=temp%3+1;
            temp/=3;
        }
        if(length>s.size())continue;
        string res="";
        int idx = 0;
        bool flag= true;
        for(int j=0;j<4;j++){
            string num = s.substr(idx,t[j]);
            idx+=t[j];
            if((num.size()>1&&num[0]=='0')||stoi(num)>255){
                flag=false;
                break;
            }
            res+=num+".";
        }
        if(flag){
            res.pop_back();
            if(res.size()==s.size()+3)
              v.push_back(res);
        }
    }
    return v;
}
};
