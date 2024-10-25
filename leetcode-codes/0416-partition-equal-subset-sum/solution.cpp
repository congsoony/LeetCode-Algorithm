#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int sum;
    bool canPartition(vector<int>& nums) {
        sum = accumulate(nums.begin(),nums.end(),0);
        dp = vector<vector<int>>(nums.size()+1,vector<int>(sum+1,-1));
        if(sum%2)return false;
        sum/=2;
        return dfs(nums);
    }
    bool dfs(vector<int>&nums,int idx=0,int total=0){
        if(total>=sum)return total==sum;
        if(idx>=nums.size())return 0;
        int &cache = dp[idx][total];
        if(cache !=-1)return cache;
        bool res =false;
        if(total+nums[idx]<=sum) 
            res |= dfs(nums,idx+1,total+nums[idx]);
        res |= dfs(nums,idx+1,total);
        return cache=res;
    }
};
