class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0, cnt = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == ' ' || s[i] == 0) {
                if (cnt)
                    res = cnt;
                cnt = 0;
            }
            else {
                cnt++;
            }
        }
        return res;
    }
};
