#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res(a.rbegin(), a.rend());
        res.push_back('0');
        if (a.size() < b.size())res.resize(b.size() + 1, '0');
        reverse(b.begin(), b.end());
        for (int i = 0; i < res.size(); i++) {
            if (i < b.size())
                res[i] += b[i] - '0';
            if (res[i] >= '2') {
                res[i] -= 2;
                res[i + 1]++;
            }
        }

        if (res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
