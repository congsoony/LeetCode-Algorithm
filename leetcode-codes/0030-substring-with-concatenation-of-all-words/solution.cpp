class Solution {
public:
vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> res;
    unordered_map<string, int> m;
    for (string &t : words)
        m[t]++;
    int len = words[0].size();
    int cnt = words.size();
    int size = s.size();

    for (int i = 0; i < len; i++)
    {
        unordered_map<string, int> m2;
        for (int j = i; j < cnt * len; j += len)
        {
            m2[s.substr(j, len)]++;
        }
        if(m==m2)res.push_back(i);
        for (int j = len+i; j <= size - len * cnt; j += len)
        {
            if (--m2[s.substr(j - len, len)] == 0)
            {
                m2.erase(s.substr(j - len, len));
            }
            if (++m2[s.substr(j + len * (cnt - 1), len)] == 0)
            {
                m2.erase(s.substr(j + len * (cnt - 1), len));
            }
            if (m == m2)
                res.push_back(j);
        }
    }
    sort(res.begin(),res.end());
    return res;
}
};
