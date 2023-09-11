class Solution {
public:
bool issame(unordered_map<char,int> &m1,unordered_map<char,int> &m2){
	for(auto it:m2){
		if(m1[it.first]<it.second)return false;
	}
	return true;
}
string minWindow(string s, string t) {
	if(s.size()<t.size())return "";
	unordered_map<char,int> m1,m2;
	for(char c: t)m2[c]++;
	int Min=1e8;
	int l=0;
	int left =0;
	for(int i=0;i<s.size();i++){
		if(m2.count(s[i])==0)continue;
		m1[s[i]]++;
		while(m1.size()==m2.size()&&issame(m1,m2)){
			if(i-l+1<Min){
				Min = i-l+1;
				left=l;
			}
			if(m1.count(s[l])){
				m1[s[l]]--;
				if(m1[s[l]]==0)
					m1.erase(s[l]);
			}
			l++;
		}
	}
	if(Min==1e8) return "";	
	return s.substr(left,Min);        
}
};
