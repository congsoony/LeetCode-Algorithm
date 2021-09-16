//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int a[21] = {0 };
		for (int i : bills) {
			a[i]++;
			if (i == 10) {
				if (a[5] == 0)return false;
				a[5]--;
			}
			else if(i==20){
				if (a[5] && a[10])a[5]--, a[10]--;
				else if (a[5] >= 3)a[5] -= 3;
				else return false;
			}
		}
		return true;
	}
};
