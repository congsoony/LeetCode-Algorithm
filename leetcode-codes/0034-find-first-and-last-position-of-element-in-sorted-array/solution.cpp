class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return{ -1, -1 };
		int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
		int idx2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
		if (idx >= nums.size())
			return{ -1, -1 };
		if (nums[idx] == target)
			return{ idx, idx2-1 };
		return{ -1, -1 };
	}
};
