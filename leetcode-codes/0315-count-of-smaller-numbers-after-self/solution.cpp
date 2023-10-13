int n;
class Solution {
public:
vector<int> tree;
void update(int idx){
    for(tree[idx+=n]++;idx>1;idx>>=1){
        tree[idx>>1]=tree[idx]+tree[idx^1];
    }
}
int query(int l,int r){
    int res=0;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1)res+=tree[l++];
        if(r&1)res+=tree[--r];
    }
    return res;
}
vector<int> countSmaller(vector<int>& nums) {
    vector<pair<int,int>> v;
    n=nums.size();
    tree=vector<int>(n*2);
    vector<int> res(n);
    for(int i=0;i<n;i++)v.push_back({nums[i],i});
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        int idx = v[i].second;
        res[idx]=query(idx,n-1)-query(idx,idx);
        update(idx);
    }
    return res;
}
};
