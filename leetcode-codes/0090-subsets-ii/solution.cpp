class Solution {
public:
int check[10];
set<vector<int>> s;
vector<int> v;
void dfs(vector<int>&nums,int idx=0){
    s.insert(v);
    for(int i=idx;i<nums.size();i++){       
            v.push_back(nums[i]);
            dfs(nums,i+1);
            v.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    dfs(nums);
    return vector<vector<int>>(s.begin(),s.end());
}
};
