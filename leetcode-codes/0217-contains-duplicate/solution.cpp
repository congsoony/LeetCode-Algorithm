class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i: nums)if(m[i]++>0) return true;
        return false;
    }
};
