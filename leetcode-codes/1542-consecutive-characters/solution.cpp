//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int maxPower(string s) {
		int _max = 0;
		char before = -1;
		int cnt = 1;
		for (char c : s) {
			if (before == c)
				cnt++;
			else
				cnt = 1;
			_max = max(_max, cnt);
			before = c;
		}
        return _max;
	}
};
