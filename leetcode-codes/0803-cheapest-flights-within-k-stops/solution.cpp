#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> v[101];
        for(vector<int> &f :flights){
            v[f[0]].push_back({f[1],f[2]});
        }
        vector<int> dist(101,1e9);
        dist[src]=0;
        queue<pair<int,int>> q;
        q.push({src,0});
        int h=0;
        while(!q.empty()){
            int qsize= q.size();
            while(qsize--){
                int cur,sumcost;
                tie(cur,sumcost) = q.front();
                q.pop();
                for(int i =0;i<v[cur].size();i++){
                    int next = v[cur][i].first;
                    int ncost = sumcost+v[cur][i].second;
                    if(dist[next]>ncost){
                        dist[next]=ncost;
                        q.push({next,ncost});
                    }
                }
            }
            h++;
            if(h>k)
                break;
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};
