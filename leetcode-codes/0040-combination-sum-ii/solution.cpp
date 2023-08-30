class Solution {
public:
vector<int>num,v;
vector<vector<int>> res;
void dfs(vector<int>& can,int target,int idx=1){
    if(target==0){
        res.push_back(v);
        return;
    }

    for(int i=idx;i<=target;i++){
        if(num[i]>0&&target-i>=0){
            v.push_back(i);
            num[i]--;
            dfs(can,target-i,i);
            num[i]++;
            v.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    num=vector<int>(51);
    for(int t:candidates)num[t]++;
    dfs(candidates,target);
    for(int i=0;i<res.size();i++){
        for(int j:res[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return res;
}
};
