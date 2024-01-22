#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
		string res;
		map<char,int> m,in;
		for(char c:s)m[c]++;
		for(char c:s){
			while(!res.empty()&&res.back() > c && m[res.back()]-1>=0&&in[c]==0){
				in[res.back()]=0;
				res.pop_back();
			}
			if(in[c]==0){
				res+=c;
				in[c]=1;
			}
			m[c]--;
		}
		return res;
    }
};
