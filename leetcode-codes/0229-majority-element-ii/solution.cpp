class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> m;
        int n = nums.size()/3;
        for(int i: nums)m[i]++;
        for(auto it:m) if(it.second>n)res.push_back(it.first);
        return res;
    }
};
