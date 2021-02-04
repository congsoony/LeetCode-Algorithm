class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int c = s[i] - 'A' + 1;
            result += c * pow(26, cnt++);
        }
        return result;

    }
};
