#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      int sSize = s.size();
        if (sSize <= 1) {
            return false;
        }
        auto index = (s + s).find(s, 1);
        return index < sSize;
    }
};
