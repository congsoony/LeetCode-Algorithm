#include <bits/stdc++.h>
using namespace std;
int dy[2] = { 1,-1 };
int dx[2] = { 0,1 };
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> v(numRows);
        string ret;
        int idx = 0;
        bool flag = false;
        for (int i = 0; i < s.size(); i++) {
            v[idx] += s[i];
            if (idx == (numRows - 1) || idx == 0)flag = !flag;
            idx += (flag ? 1 : -1);
        }
        for (string t : v)
            ret += t;

        return ret;
    }
};
