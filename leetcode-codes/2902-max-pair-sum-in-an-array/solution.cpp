class Solution {
public:
int maxSum(vector<int>& nums) {
    int res=-1;
    vector<int> number(nums.size());
    for(int i=0;i<nums.size();i++){
        int temp = nums[i];
        while(temp){
            number[i]=max(number[i],temp%10);
            temp/=10;
        }
    }
    for(int i=0;i<nums.size()-1;i++){
        for(int j=i+1;j<nums.size();j++){
            if(number[i]==number[j]){
                res=max(res,nums[i]+nums[j]);
            }       
        }
    } 
    return res;
}
};
