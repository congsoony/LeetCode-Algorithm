class Solution {
public:
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if(nums.size()==0)return res;
    int b = nums[0];
    int cnt=0;
    
    for(int i=1;i<nums.size();i++){
        if(b+1==nums[i]){
            cnt++;
        }
        else{
            if(cnt!=0)
                res.push_back(to_string(b-cnt)+"->"+to_string(b));
            else
                res.push_back(to_string(b));
            cnt=0;
        }
        b=nums[i];
    }
    if(cnt!=0)
        res.push_back(to_string(b-cnt)+"->"+to_string(b));
    else
        res.push_back(to_string(b));
    return res;
}
};
