class Solution {
public:
bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
	if(nums.empty()||indexDiff==0)return false;
	multiset<int> s;
	for(int i=0;i<nums.size();i++){
		if(i>indexDiff){
			s.erase(nums[i-indexDiff-1]);
		}
		auto it =s.lower_bound(nums[i]-valueDiff);
		if(it!=s.end()){
			int dif = *it-nums[i];
			if(dif<=valueDiff){
				return true;
			}
		}
		s.insert(nums[i]);
	}
	return false;        
}

};
