#define ll long long
int n;
class Solution {
public:
vector<ll> tree,sum;
vector<pair<ll,ll>> v;
int init(int s=0,int e=n-1,int node=1){
    if(s==e)return tree[node];
    int mid = (s+e)>>1;
    return tree[node]=init(s,mid,node*2)+init(mid+1,e,node*2+1);
}
ll query(ll l,ll r,int s=0,int e=n-1,int node=1){
    if(l>v[e].first||r<v[s].first)return 0;
    if(l<=v[s].first&&v[e].first<=r)return tree[node];
    int mid =(s+e)>>1;
    return query(l,r,s,mid,node*2)+query(l,r,mid+1,e,node*2+1);
}
void update(int idx,int s=0,int e=n-1,int node=1){
    if(!(s<=idx&&idx<=e))return;
    if(s==e){
        tree[node]--;
        return;
    }
    int mid =(s+e)>>1;
    update(idx,s,mid,node*2);
    update(idx,mid+1,e,node*2+1);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int countRangeSum(vector<int>& nums, int lower, int upper) {
    int res=0;
	n = nums.size();
    tree=vector<ll>(n*4,1);
    sum=vector<ll>(n);
    sum[0]=nums[0];
    unordered_map<int,int> m;
    init();
    v.push_back({sum[0],0});
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+nums[i];
        v.push_back({sum[i],i});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)m[v[i].second]=i;
    ll Lower=lower,Upper=upper;
    for(int i=0;i<n;i++){
        res+=query(Lower,Upper);
        int idx = m[i];
        update(idx);
        Lower+=nums[i];
        Upper+=nums[i];
    }
	return res;
}
};
