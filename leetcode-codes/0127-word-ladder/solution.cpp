class Solution {
public:
int bfs(string &begin,string &end,vector<string>& wordlist){
    queue<string> q;
    q.push(begin);
    unordered_set<string> m(wordlist.begin(),wordlist.end());
    unordered_map<string,int> check;
    check[begin]=0;
    int res=0;
    while(!q.empty()){
        int qsize=q.size();
        while(qsize--){
            string cur = q.front();
            q.pop();
            if(cur==end)return res+1;
            string next = cur;
            for(int i=0;i<next.size();i++){
                for(char c='a';c<='z';c++){
                    next[i]=c;
                    if(m.count(next)&&check.count(next)==0){
                        check[next]=res+1;
                        q.push(next);
                    }
                }
                next[i]=cur[i];
            }
        }
        res++;
    }
    return 0;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    return bfs(beginWord,endWord,wordList);
}
};
