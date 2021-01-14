class Solution {
public:
	bool canJump(vector<int>& nums) {
		int cur = nums.size() - 1;
		for (int i = nums.size()-2; i >=0; i--){
			if (cur <= nums[i] + i){
				cur = i;
			}
		}
		return !cur;
	}
};
