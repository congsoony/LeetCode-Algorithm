class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        int res = dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
            res=max(dp[i],res);
        }
        return res;
    }
};
