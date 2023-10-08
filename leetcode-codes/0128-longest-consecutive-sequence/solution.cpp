class Solution {
public:
int longestConsecutive(vector<int>& nums) {
	if(nums.empty())return 0;
	sort(nums.begin(),nums.end());
	int res = 1;
	unordered_set<int> s(nums.begin(),nums.end());
	for(int i=0;i<nums.size();i++){
		int left = nums[i];
		int cnt = 1;
		while(s.count(--left)){
			cnt++;
			s.erase(left);
		}
		int right = nums[i];
		while(s.count(++right)){
			cnt++;
			s.erase(right);
		}
		res=max(res,cnt);
	}
	return res;
}
};
