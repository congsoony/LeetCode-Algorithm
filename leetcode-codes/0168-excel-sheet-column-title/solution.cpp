class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        n--;
        if (n == 0)
            return "A";
        while (n >= 0) {
            char c = n % 26+'A';
            n /= 26;
            res += c;
            n--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
