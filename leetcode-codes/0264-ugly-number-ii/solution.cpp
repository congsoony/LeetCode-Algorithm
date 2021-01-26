class Solution {
public:
	int nthUglyNumber(int n) {
		int a = 0, b = 0, c = 0;
		vector<int> v = { 1 };
		while(v.size()<n){
			int A = v[a] * 2;
			int B = v[b] * 3;
			int C = v[c] * 5;
			vector<int> v2 = {A,B,C };
			sort(v2.begin(), v2.end());
			v.push_back(v2[0]);
			if (v2[0] == A)a++;
			if (v2[0] == B)b++;
			if (v2[0]==C)c++;
		}
		return v.back();
	}
};
