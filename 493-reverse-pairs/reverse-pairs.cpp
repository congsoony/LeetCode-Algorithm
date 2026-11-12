#include<bits/stdc++.h>
using namespace std;
int n=1;
class Solution {
public:
    vector<vector<long long>> tree;
    vector<long long> v;
    int reversePairs(vector<int>& nums) {
        int res = 0 ;
        n = nums.size();
        tree.resize(n*4);
        for(int i =0;i<n;i++)v.push_back(nums[i]);
        init();
        for(int i =0;i<n;i++){
            res += query(i+1,n-1,nums[i]);
        }
        return res;
    }
    void init(int s=0,int e=n-1,int node=1){
        if(s==e){
            tree[node] = {v[s]*2};
            return;
        }
        
        int mid = (s+e)/2;
        init(s,mid,node*2);
        init(mid+1,e,node*2+1);
        tree[node].resize(e-s+1);
        merge(tree[node*2].begin(),tree[node*2].end(),tree[node*2+1].begin(),tree[node*2+1].end(),tree[node].begin());
    }
    int query(int l,int r,long long val,int s=0,int e=n-1,int node=1){
        if(l>e ||r<s)return 0;
        if(l<=s&&e<=r) return lower_bound(tree[node].begin(),tree[node].end(),val) - tree[node].begin();
        int mid = (s+e)/2;
        return query(l,r,val,s,mid,node*2) + query(l,r,val,mid+1,e,node*2+1);
    }
};
