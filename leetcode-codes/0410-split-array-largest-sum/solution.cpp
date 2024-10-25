#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0,r=accumulate(nums.begin(),nums.end(),0);
        int res = 2e9;
        while(l<=r){
            int mid = (l+r)>>1;
            int sum=0;
            int cnt =1;
            int _max =0;
            for(int i =0;i<nums.size();i++){
                if(sum+nums[i]>mid){
                    _max = max(_max,sum);
                    sum=0;
                    cnt++;
                }
                sum+=nums[i];
            }
            _max = max(sum,_max);
            if(cnt<=k){
                r=mid-1;
                res = min(res,_max);
            }
            else{
                l= mid+1;
            }
        }
        return res;
    }
};
