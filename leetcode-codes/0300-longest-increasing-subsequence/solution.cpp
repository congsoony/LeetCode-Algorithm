class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
	vector<int> res={-1000000};
	for(int t:nums){
		if(res.back()<t){
			res.push_back(t);
		}
		else{
			*lower_bound(res.begin(),res.end(),t)=t;
		}
	}
	return res.size()-1;        
}
};
