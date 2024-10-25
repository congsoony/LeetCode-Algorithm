//By 콩순이냉장고
#include<bits/stdc++.h>
using namespace std;
class Trie {
public:
    Trie * children[26];
    bool terminal=false;
    Trie() {
        memset(children,0,sizeof(children));
    }
    
    void insert(string word) {
        insert(word,0);
    }
    void insert(string &s,int idx){
        if(s[idx]=='\0'){
            terminal=true;
            return;
        }
        int next = s[idx]-'a';
        if(!children[next])children[next]=new Trie();
        children[next]->insert(s,idx+1);
    }

    bool search(string &word,int idx) {
        if(word[idx]=='\0'){
            return terminal;
        }
        int next=word[idx]-'a';
        if(!children[next])return false;
        return children[next]->search(word,idx+1);
    }
    
    bool startsWith(string &prefix,int idx) {
        if(prefix[idx]=='\0')return true;
        int next = prefix[idx]-'a';
        if(!children[next])return false;
        return children[next]->startsWith(prefix,idx+1);
    }

    
    bool search(string word) {
        return search(word,0);
    }
    
    bool startsWith(string prefix) {
        return startsWith(prefix,0);
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
