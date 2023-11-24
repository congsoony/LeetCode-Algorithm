class Solution {
public:

int maxRotateFunction(vector<int>& nums) {
	int sum=0;
	int sumul = 0;
	for(int i=0;i<nums.size();i++){
		sum+=nums[i];
		sumul+=i*nums[i];
	}
	int res = sumul;
	for(int i=nums.size()-1;i>=0;i--){
		sumul+=sum -nums[i]*nums.size();
		res = max(res,sumul);
	}
	return res;
}
};
