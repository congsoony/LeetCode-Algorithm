
#include<bits/stdc++.h>
using namespace std;
class BrowserHistory {
public:
	list<string> l;
	list<string>::iterator cur;

    BrowserHistory(string homepage) {
		l = {homepage};
		cur=l.begin();
    }
    void visit(string url) {
		cur++;
		l.erase(cur,l.end());
		l.push_back(url);
		cur=l.end();
		cur--;
    }
    
    string back(int steps) {
		while(cur!=l.begin()&&steps--){
			cur--;
		}
        return *cur;
    }
    
    string forward(int steps) {
		while(cur!=l.end()&& steps--)cur++;
		if(cur==l.end())cur--;
		return *cur;
    }
};
