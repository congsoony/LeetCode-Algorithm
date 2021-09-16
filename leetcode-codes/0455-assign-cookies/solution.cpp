//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int r = 0;
		int cnt = 0;
		for (int i = 0; i < g.size()&&r<s.size(); i++) {
			while (r<s.size()&&g[i] > s[r])r++;
				if (r < s.size()&&g[i] <= s[r])
					cnt++;
				r++;
		}
		return cnt;
	}
};
