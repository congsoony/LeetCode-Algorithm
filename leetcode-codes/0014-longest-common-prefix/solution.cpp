class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res = "";
        if(strs.size()==0)
            return res;
        
		for (int i = 0; i < 200; i++){
			bool flag = false;
			if (i >= strs[0].size())
				break;
			char c = strs[0][i];
			for (int j = 0; j < strs.size(); j++){
				if (i >= strs[j].size()){
					flag = true;
					break;
				}
				if (strs[j][i] != c){
					flag = true;
					break;
				}
			}
			if (flag)
				break;
			res += c;
		}
		return res;
	}
};
