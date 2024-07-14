#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> dp;
	vector<int> sum;
    int splitArray(vector<int>& nums, int k) {
        dp = vector<vector<int>>(nums.size()+1,vector<int>(k+1,-1));
		sum.resize(nums.size()+1);
		for(int i=1;i<=nums.size();i++)sum[i]=sum[i-1]+nums[i-1];
		return dfs(nums.size(),k);		
    }
	int dfs(int i,int j){
		if(j==1)return sum[i];
		int &cache = dp[i][j];
		if(cache!=-1)return cache;
		int _min=1e9;
		for(int k=j-1;k<i;k++){
			int before = sum[i]-sum[k];
			int large = max(before,dfs(k,j-1));
			_min = min(_min,large);
		}
		return cache=_min;
	}
};
