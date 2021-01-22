class Solution {
public:
    int climbStairs(int n) {
        
        int fibo[50]={0,1,2};
        for(int i=3;i<=n;i++)
            fibo[i]=fibo[i-1]+fibo[i-2];
        return fibo[n];
    }
};
