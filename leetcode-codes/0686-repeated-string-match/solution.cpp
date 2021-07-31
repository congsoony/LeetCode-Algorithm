#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = a;
        int cnt = 1;
        while (s.size() < b.size()) {
            s += a;
            cnt++;
        }
        if (s.find(b) != -1)
            return cnt;
        else {
            s += a;
            if (s.find(b) != -1)
                return cnt + 1;
        }
        return -1;
    }
};
