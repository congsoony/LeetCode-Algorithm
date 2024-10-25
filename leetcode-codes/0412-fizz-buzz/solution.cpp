#include<string>
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        vector<string> f={"","Fizz","Buzz"};
        for(int i =1;i<=n;i++){
            res[i-1]=to_string(i);
            if(i%3==0|| i%5==0)
                res[i-1]=f[i%3==0]+f[(i%5==0)<<1];
        }
        return res;
    }
};
