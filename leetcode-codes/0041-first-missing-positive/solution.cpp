class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    vector<bool> check(nums.size()+10);
    for(int i: nums)if(i>0&&i<check.size()) check[i]=1;
    
    for(int i=1;i<check.size();i++)if(!check[i])return i;
    return -1;

}
};
