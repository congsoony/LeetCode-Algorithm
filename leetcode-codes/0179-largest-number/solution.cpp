#include <bits/stdc++.h>
using namespace std;
bool cmp(int& a, int &b) {
	string ab = to_string(a) + to_string(b);
	string ba = to_string(b) + to_string(a);
	return ab > ba;
}
class Solution {
public:
  
string largestNumber(vector<int>& nums) {
	sort(nums.begin(), nums.end(), cmp);
	string res = "";
	for (int t : nums)
		res += to_string(t);
    if(res[0]=='0') return "0";
	return res;
}
};
