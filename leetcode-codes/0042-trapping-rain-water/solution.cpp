class Solution {
public:
int trap(vector<int>& height) {
    int res=0;
    int n = height.size();
    vector<int> lv(n),rv(n);
    lv[0]=height[0];
    for(int i=1;i<n;i++)lv[i]=max(lv[i-1],height[i]);
    rv[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--)rv[i]=max(rv[i+1],height[i]);
    
    for(int i=0;i<n;i++){
        res+=min(lv[i],rv[i])-height[i];
    }
    return res;
}
};
