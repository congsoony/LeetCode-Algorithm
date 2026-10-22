#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> res;
    vector<int> lexicalOrder(int n) {
        for(int i =1;i<=9;i++){
            if(i>n)break;
            dfs(i,n);
        }
        return res;
    }
    void dfs(int cur,int n){
        res.push_back(cur);
        for(int i =0;i<10;i++){
            int next = cur*10+i;
            if(next>n)break;
            dfs(next,n);
        }
    }
};