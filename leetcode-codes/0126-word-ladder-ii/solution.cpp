class Solution {
public:
vector<vector<string>> res;
string start, fin;
unordered_map<string, int> check;
vector<string> v;
int h;
int bfs(unordered_set<string> &m)
{
    queue<string> q;
    q.push(start);
    check[start] = 0;
    int ans = 0;
    while (!q.empty())
    {
        int qsize = q.size();
        while (qsize--)
        {
            string cur = q.front();
            q.pop();
            if (cur == fin)
                return ans;
            string next = cur;
            for (int i = 0; i < cur.size(); i++)
            {
                for (char c = 'a'; c <= 'z'; c++)
                {
                    next[i] = c;
                    if (m.count(next) && check.count(next) == 0)
                    {
                        check[next] = ans + 1;
                        q.push(next);
                    }
                }
                next[i] = cur[i];
            }
        }
        ans++;
    }
    return -1;
}

void dfs(string cur, int len, unordered_set<string> &m)
{
    if (len<=0)
    {
        if(!v.empty()&&v.back()==start)
            res.push_back(vector<string>(v.rbegin(),v.rend()));
        return;
    }
    string next = cur;
    for (int i = 0; i < cur.size(); i++)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            next[i] = c;
            if(m.count(next)){
                if(check[next]==len-1){
                    v.push_back(next);
                    dfs(next,len-1,m);
                    v.pop_back();
                }
            }
        }
        next[i] = cur[i];
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> m(wordList.begin(), wordList.end());
    start = beginWord;
    fin = endWord;
    int len = bfs(m);
    if (len == -1)
        return {};
    v.push_back(fin);
    m.insert(start);
    dfs(fin, len, m);
    return res;
}
};
