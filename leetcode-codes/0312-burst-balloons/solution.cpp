class Solution {
public:
vector<vector<int>> dp;
int dfs(vector<int>& nums,int l,int r){
	if(l>r)return 0;
	int &cache = dp[l][r];
	if(cache!=-1)return cache;
	int left = nums[l-1];
	int right = nums[r+1];
	for(int i=l;i<=r;i++){
		cache = max(cache,left*nums[i]*right+dfs(nums,l,i-1)+dfs(nums,i+1,r));
	}
	return cache;
}
int maxCoins(vector<int>& nums) {
	int n =nums.size();
	nums.insert(nums.begin(),1);
	nums.push_back(1);
	dp = vector<vector<int>>(n+2,vector<int>(n+2,-1));
	return dfs(nums,1,n);
}
};
