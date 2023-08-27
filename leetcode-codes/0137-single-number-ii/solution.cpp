class Solution {
public:
int singleNumber(vector<int>& nums) {
    unordered_map<int,int> m;
    for(int t:nums)m[t]++;
    for(auto[a,b]:m)if(b==1)return a;
    return -1;
}
};
