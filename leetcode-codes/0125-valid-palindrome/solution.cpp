//By 콩순이냉장고
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for (char c : s) {
            c = tolower(c);
            if (('a' <= c && c <= 'z')||'0'<=c&&c<='9')
                temp += c;
        }
        int left = 0;
        int right = temp.size() - 1;
        while (left <= right && temp[left] == temp[right])
            left++, right--;
        return left > right;
    }
};
