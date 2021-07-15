class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int num = 2; num <= n; num++) {
            int add = 1;
            string s="";
            for (int i = 0; i < ans.size(); i+=add) {
                int cnt = 1;
                for (int j = i + 1; j < ans.size(); j++,cnt++) {
                    if (ans[i] != ans[j])break;
                }
                s += to_string(cnt) + ans[i];
                add = cnt;
            }
            ans = s;
        }

        return ans;
    }
   
};
