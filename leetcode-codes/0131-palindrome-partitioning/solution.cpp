class Solution {
public:

	vector<vector<string>> res;
	vector<vector<string>> partition(string s) {
		vector<string> v;
		dfs(s, v, 0);
		return res;

	}

	void dfs(string& s, vector<string> &v, int idx) {
		if (idx >= s.size()) {
			res.push_back(v);
			return;
		}
		
		for (int i = idx; i < s.size(); i++) {
			int left = idx;
			int right = i;
			if (same(s,left,right)) {
				v.push_back(s.substr(left, right - left + 1));
				dfs(s, v, right+1);
				v.pop_back();
			}
		}
	}
	bool same(string & s,int left, int right) {
		while (left <= right)
			if (s[left++] != s[right--])
				return false;
		return true;
	}
};
