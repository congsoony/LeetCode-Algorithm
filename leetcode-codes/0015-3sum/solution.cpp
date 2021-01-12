class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> v;
		sort(nums.begin(), nums.end());
		if (nums.size() <3)
			return v;
		for (int i = 0; i < nums.size()-1; i++){
			if (i>0 && nums[i] == nums[i - 1])
				continue;
			int left = i + 1;
			int right = nums.size() - 1;
			int target = -nums[i];
			
			while (right-left>0){
				if (nums[left] + nums[right] == target){
					v.push_back({ -target, nums[left], nums[right] });
					left++;
					right--;
					while (right - left > 0 && nums[left - 1] == nums[left])
						left++;
					while (right - left > 0 && nums[right + 1] == nums[right])
						right--;

				}
				else if (nums[left] + nums[right] > target){
					right--;
				}
				else{
					left++;
				}
			}
		}
		return v;
	}
};
