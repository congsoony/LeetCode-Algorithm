#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int n,K;
    vector<ll>dp;
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        K= k;
        dp = vector<ll>(n,-1);
        return dfs(0,arr);
    }
    ll dfs(int cur,vector<int>& arr){
        if(cur>=n)return 0;
        ll &cache = dp[cur];
        if(cache!=-1)
            return cache;
        ll _max = 0;
        for(int i =1;i<=K;i++){
            if(cur+i<=n){
                _max = max((ll)arr[cur+i-1],_max);
                cache = max(cache,_max*i+dfs(cur+i,arr));
            }
        }
        return cache;
    }
};
