class Solution {
public:
	string longestPalindrome(string s) {
		int Max = 1;
		string ms = s.substr(0, 1);
		for (int i = 1; i < s.size(); i++){
			findMaxstring(i - 1, i, 0, Max, s, ms);
			findMaxstring(i - 1, i + 1, 1, Max, s, ms);
		}
        return ms;
	}
    
	void findMaxstring(int left, int right, int len, int &Max, string &s, string &ms){
		while (left >= 0 && right < s.size() && s[left] == s[right]){
			len += 2;
			if (Max < len){
				Max = len;
				ms = s.substr(left, len);
			}
			left--;
			right++;
		}
	}
    
};
