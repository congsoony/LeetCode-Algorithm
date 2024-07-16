

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<int> prefix;
    vector<vector<int>> dp[2];
    int stoneGameVII(vector<int>& stones) {
       n = stones.size();
       dp[0]=dp[1]=vector<vector<int>>(n+1,vector<int>(n+1,-1));
       prefix=vector<int>(n+1);
       for(int i=1;i<=n;i++)prefix[i]=prefix[i-1]+stones[i-1];
       for(int i=1;i<=n;i++)
        cout<<prefix[i]<<" ";
        cout<<endl;
       return dfs(1,n); 
    }
    int dfs(int i,int j,int alice=0){
        if (i>j)return 0;
        int &cache = dp[alice][i][j];
        if(cache!=-1)return cache;
        if(alice==0){
            return cache = max(dfs(i+1,j,1)+prefix[j]-prefix[i] , dfs(i,j-1,1)+prefix[j-1]-prefix[i-1]);
        }
        return cache = min(dfs(i+1,j,0)-(prefix[j]-prefix[i]) , dfs(i,j-1,0)-(prefix[j-1]-prefix[i-1]));
    }
};

