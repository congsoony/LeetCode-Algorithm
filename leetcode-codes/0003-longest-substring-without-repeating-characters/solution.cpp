class Solution {
public:
int lengthOfLongestSubstring(string s) {
    if(s.size()==0) return 0;
    unordered_set<int> t(s.begin(),s.end()),se;
    int maxlen = t.size();
    int j =0;
    int res=0;
    for(int i=0;i<s.size();i++){
        while(se.count(s[i]))
            se.erase(s[j++]);
        se.insert(s[i]);
        res = max(res,(int)se.size());
        if(maxlen==res) return maxlen;
    }
    return res;
}
};
