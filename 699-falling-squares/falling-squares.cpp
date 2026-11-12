#include<bits/stdc++.h>
using namespace std;
int n;
    
class Solution {
public:
    vector<int> tree,lazy;
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> res;
        vector<int> x;

        for(vector<int> &p:positions){
            x.push_back(p[0]);
            x.push_back(p[0]+p[1]);
        }

        sort(x.begin(),x.end());
        n = x.size();
        lazy=tree = vector<int>(x.size()*4);
        int _max = 0 ;
        for(vector<int> &p:positions){
            int l =lower_bound(x.begin(),x.end(),p[0]) - x.begin();
            int r = lower_bound(x.begin(),x.end(),p[0]+p[1])-x.begin()-1;
            int q = query(l,r);
            int newh = q+p[1];
            _max = max(_max,newh);
            res.push_back(_max);
            update_range(l,r,newh);
        }
        return res;
    }
    void update_lazy(int s,int e,int node){
        if(lazy[node]){
            tree[node]=max(tree[node],lazy[node]);
            if(s!=e){
                lazy[node*2] = max(lazy[node*2],lazy[node]);
                lazy[node*2+1] = max(lazy[node*2+1],lazy[node]);
            }
            lazy[node]=0;
        }
    }
    void update_range(int l,int r,int val,int s=0,int e = n-1,int node=1){
        update_lazy(s,e,node);
        if(l>e || r<s)return;
        if(l<=s&&e<=r){
            tree[node]  = max(tree[node],val);
            if(s!=e){
                lazy[node*2] =max(lazy[node*2],val);
                lazy[node*2+1] = max(lazy[node*2+1],val);
            }
            return;
        }
        int mid = (s+e)/2;
        update_range(l,r,val,s,mid,node*2);
        update_range(l,r,val,mid+1,e,node*2+1);
        tree[node] = max(tree[node*2],tree[node*2+1]);
    }
    int query(int l,int r,int s=0,int e=n-1,int node=1){
        update_lazy(s,e,node);
        if(l>e||r<s)return 0;
        if(l<=s&&e<=r)return tree[node];
        int mid = (s+e)/2;
        return max(query(l,r,s,mid,node*2),query(l,r,mid+1,e,node*2+1));
    }
};