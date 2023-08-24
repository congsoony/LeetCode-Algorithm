class Solution {
public:
    int tonum(char c){ return c-'0';}
    string multiply(string num1, string num2) {
        int size1= num1.size();
        int size2 = num2.size();
        vector<int> res(size1+size2);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<size2;i++){
            for(int j=0;j<size1;j++){
                int temp =tonum(num1[j])*tonum(num2[i]);
                res[i+j]+=temp%10;
                if(res[i+j]>=10){
                    res[i+j+1]++;
                    res[i+j]%=10;
                }
                res[i+j+1]+=temp/10;
                if(res[i+j+1]>=10){
                    res[i+j+2]++;
                    res[i+j+1]%=10;
                }
            }
        }
        while(res.size()>1&&res.back()==0)res.pop_back();
        string s;
        reverse(res.begin(),res.end());
        for(int i:res)s+=to_string(i);
        return s;
    }
};
