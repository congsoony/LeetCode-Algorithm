class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> v;
        for(int i:nums)if(i!=val)v.push_back(i);
        int res = nums.size()-v.size();
        nums=v;
        return v.size();
    }
};
