class Solution {
public:
    int dp[100];
    int dfs(string& s,int idx=0) {
	if (idx >= s.size())return 1;
	int& res = dp[idx];
	if (res != -1)return res;
	int a = s[idx] - '0';
	if (a)
		res = dfs(s, idx + 1);
	if (a&&idx + 1 < s.size()) {
		int b = a * 10 + s[idx + 1] - '0';
		if (1<=b&&b<=26)
			res += dfs(s, idx + 2);
	}
	return res = (res == -1 ? 0 : res);
}

int numDecodings(string s) {
	memset(dp, -1, sizeof(dp));
	return dfs(s);
}
};
