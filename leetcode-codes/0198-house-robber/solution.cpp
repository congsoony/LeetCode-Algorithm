#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[201];
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return dfs(nums);
    }
    int dfs(vector<int>& nums,int idx=0){
        if(idx>=nums.size()){
            return 0;
        }
        int &cache = dp[idx];
        if(cache!=-1)return cache;
        return cache = max(dfs(nums,idx+2)+nums[idx],dfs(nums,idx+1));
    }
};
