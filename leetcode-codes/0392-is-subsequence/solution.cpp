class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l=0;
        for(char c:t){
            if(s[l]==c)l++;
            if(l==s.size())return true;
        }
        return l==s.size();
    }
};
