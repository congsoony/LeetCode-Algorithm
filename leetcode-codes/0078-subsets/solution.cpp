class Solution {
public:
    vector<vector<int>> res;
    int visit[11];
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        vector<int> v;
        memset(visit, 0, sizeof(visit));
        res.push_back(v);
        for (int i = 1; i <= nums.size(); i++) {
            make(i, 0, nums, v);
        }
        return res;
    }
    void make(int len, int idx,vector<int> &nums,vector<int> &v, int depth=0) {
        if(depth >= len) {
            res.push_back(v);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (!visit[i]) {
                visit[i] = 1;
                v.push_back(nums[i]);
                make(len, i, nums, v, depth + 1);
                visit[i] = 0;
                v.pop_back();
            }
        }
    }
};
