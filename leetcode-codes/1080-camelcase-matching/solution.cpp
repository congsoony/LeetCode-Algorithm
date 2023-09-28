class Solution {
public:
vector<bool> camelMatch(vector<string>& queries, string pattern) {
	vector<bool> res;
	string s="[a-z]*";
	for(char c:pattern){
		s+=c;
		s+="[a-z]*";
	}
	regex re(s);
	for(string &t :queries)res.push_back(regex_match(t,re));
	return res;        
}
};
