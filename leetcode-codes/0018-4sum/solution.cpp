class Solution {
public:
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    set<vector<int>> s;
    int size = nums.size();
    for (int i = 0; i < size - 3; i++){
        for (int j =size-1; j >= i+3; j--){
            int l = i + 1;
            int r = j-1;
            long long sum = nums[i] + nums[j];
            while (l < r)
            {
                long long sum2 = sum + nums[l] + nums[r];
                if (sum2 <= target)
                {
                    if (sum2 == target)
                    {
                        s.insert({nums[i],nums[l],nums[r],nums[j]});
                    }
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
    }
    return vector<vector<int>> (s.begin(),s.end());
}
};
