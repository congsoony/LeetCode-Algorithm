class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0 ;
        int res = 0;
        for(int i =0;i<n-2;i++){
            if(nums[i+1]-nums[i]==nums[i+2]-nums[i+1]){
                cnt++;
            }
            else{
                res+=(cnt*(cnt+1))/2;
                cnt=0;
            }
        }
        res+=(cnt*(cnt+1))/2;
        return res;
    }
};
