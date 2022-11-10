#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> v(nums.rbegin(), nums.rend());
        return max(getMax(nums),getMax(v));
    }
    int getMax(vector<int>& nums) {
        int res = -1e8;
        int p = 1;
        int before = -1e8;
        for (int i = 0; i < nums.size(); i++) {
            before = max(before, nums[i]);
            p *= nums[i];
            res = max({ res, before,p });
            if (p == 0)p = 1;
        }
        return res;
    }
};
