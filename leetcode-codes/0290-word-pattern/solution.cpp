class Solution {
public:
bool wordPattern(string pattern, string s) {
	stringstream ss(s);
	int idx=0;
	unordered_map<char,string> m;
	unordered_map<string,char> m2;
	string temp;
	while(getline(ss,temp,' ')){
		if(m.count(pattern[idx])){
			if(m[pattern[idx]]!=temp)return false;
		}
		if(m2.count(temp)){
			if(m2[temp]!=pattern[idx])return false;
		}

		m[pattern[idx]]=temp;
		m2[temp]=pattern[idx++];
	}
	return idx==pattern.size();
}

};
