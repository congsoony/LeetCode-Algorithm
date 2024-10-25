//By 콩순이냉장고
#include<bits/stdc++.h>
using namespace std;
class WordDictionary {
public:
    WordDictionary * children[27];
    bool terminal=false;
    WordDictionary() {
        memset(children,0,sizeof(children));
    }
    void addWord(string &s,int idx){
        if(s[idx]==0){
            terminal= true;
            return;
        }
        int next= s[idx]-'a';
        if(!children[next])
            children[next]=new WordDictionary();
      
        children[next]->addWord(s,idx+1);
    }
    void addWord(string word) {
        addWord(word,0);
    }
    
    bool search(string &s,int idx){
        if(s[idx]=='\0'){
            return terminal;
        }
        if(s[idx]=='.'){
            bool flag= false;
            for(int i =0;i<26;i++){
                if(children[i])
                    flag|=children[i]->search(s,idx+1);
            }
            return flag;
        }
        int next=s[idx]-'a';
        if(!children[next])return false;
        return children[next]->search(s,idx+1);
    }
    bool search(string word) {
        return search(word,0);
    }
};
