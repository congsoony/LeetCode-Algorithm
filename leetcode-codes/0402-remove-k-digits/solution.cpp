#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
string removeKdigits(string num, int k) {
	string res;
	int resultsize = num.size() - k;
	if (num.size() == k)
		return "0";

	for (int i = 0; i < num.size(); i++) {
		int expsize = num.size() - i;
		while (!res.empty() && res.back() > num[i]&&expsize+res.size()>resultsize) {
			res.pop_back();
		}
		if (res.size() < resultsize)
			res += num[i];
	}
	int idx = 0;
	for (; idx < res.size(); idx++)
		if (res[idx] != '0')break;
	string ans(res.begin() + idx, res.end());
	if (ans.size() == 0)
		return "0";
	return ans;
}

};
