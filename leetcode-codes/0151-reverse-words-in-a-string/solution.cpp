//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;

vector<string> split(string& s, char delimiter = ' ') {
    vector<string> v;
    stringstream ss(s);
    string temp;
    while (getline(ss, temp, delimiter)) {
        if(!temp.empty())
            v.push_back(temp);
    }
    return v;
}
class Solution {
public:
    string reverseWords(string s) {
        vector<string> rv = split(s);
        string res;
        int size = rv.size();
        for (int i = size - 1; i >= 0;i--) {
            res += rv[i] + " ";
        }
        if(!res.empty())
            res.pop_back();
        return res;
    }
};
