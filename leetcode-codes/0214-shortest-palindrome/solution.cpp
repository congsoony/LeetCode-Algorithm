class Solution {
public:
vector<int> getpi(string &s){
	vector<int> pi(s.size());
	int matched=0;
	for(int i=1;i<s.size();i++){
		while(matched>0&&s[i]!=s[matched])matched=pi[matched-1];
		if(s[i]==s[matched]){
			pi[i]=++matched;
		}
	}
	return pi;
}
string shortestPalindrome(string s) {
	string rev = s+" "+string(s.rbegin(),s.rend());
	vector<int> pi=getpi(rev);
	string tmp = s.substr(pi.back());
	return string(tmp.rbegin(),tmp.rend())+s;
}
};
