class Solution {
public:
	vector<vector<int>> v;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> res;
		dfs(candidates, res, target);
		return v;
	}
	void dfs(vector<int> &candidates,vector<int> &res, int target,int idx=0, int sum = 0){
		if (target == sum){
			v.push_back(res);
			return;
		}
		if (idx>=candidates.size()){
			return;
		}
		if (candidates[idx] + sum <= target){
			res.push_back(candidates[idx]);
			dfs(candidates, res, target, idx, sum + candidates[idx]);
			res.pop_back();
		}
		else //그이외는 target보다 크므로 탐색할필요없음
			return;

		dfs(candidates, res, target, idx + 1, sum);
				
	}
};
