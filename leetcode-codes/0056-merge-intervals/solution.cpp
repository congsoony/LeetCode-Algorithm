class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> v;
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++)
            v.push_back({ intervals[i][0],intervals[i][1] });
        sort(v.begin(), v.end());
        ans.push_back({ -1,-1 });
        for (int i = 0; i < v.size(); i++) {
            if (ans.back()[1] < v[i].first){
                ans.push_back({ v[i].first,v[i].second });
            }
            else {
                ans.back()[1] = max(v[i].second,ans.back()[1]);
            }
        }
        ans.erase(ans.begin());
     
        return ans;
    }
};

