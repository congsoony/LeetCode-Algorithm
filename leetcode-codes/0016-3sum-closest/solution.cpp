class Solution {
public:
int threeSumClosest(vector<int>& nums, int target) {
    int res= 1e8;
    int dist = 1e8;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-2;i++){
        int l = i+1;
        int r = nums.size()-1;
        while(l<r){
            int sum=nums[i]+nums[l]+nums[r];
            if(dist>abs(target-sum)){
                dist = abs(target-sum);
                res=sum;
            }
            if(sum<=target){
                l++;
            }
            else{
                r--;
            }
        }
    }    
    return res;
}
};
