int n;
class NumArray {
public:
    vector<int> tree;
    NumArray(vector<int>& nums) {
        n= nums.size();
        int h = ceil(log2(n))+1;
        int treesize = 1<<h;
        tree=vector<int>(treesize);
        init(nums);
    }
    int init(vector<int>&nums,int s=0,int e=n-1,int node=1){
        if(s==e)return tree[node]=nums[s];
        int mid = (s+e)>>1;
        return tree[node]=init(nums,s,mid,node*2)+init(nums,mid+1,e,node*2+1);
    }
    void update(int index, int val,int s=0,int e=n-1,int node=1) {
        if(!(s<=index&&index<=e))return;
        if(s==e){
            tree[node]=val;
            return;
        }
        int mid = (s+e)>>1;
        update(index,val,s,mid,node*2);
        update(index,val,mid+1,e,node*2+1);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
    int sumRange(int left, int right,int s=0,int e=n-1,int node=1) {
        if(left>e||right<s)return 0;
        if(left<=s&&e<=right){
            return tree[node];
        }
        int mid = (s+e)>>1;
        return sumRange(left,right,s,mid,node*2)+sumRange(left,right,mid+1,e,node*2+1);   
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
