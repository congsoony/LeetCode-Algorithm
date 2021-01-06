//By 콩순이냉장고
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<char, string> Map = {
	{ '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" },
	{'6', "mno" }, { '7', "pqrs" }, {'8', "tuv" }, { '9', "wxyz" }
};

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		dfs(digits, 0, result);
		return result;
	}
	void dfs(string &digits,int idx, vector<string> &v, string result=""){
		if (idx >= digits.size())
		{
			if (result == "")
				return;
			v.push_back(result);
			return;
		}
		for (int i = 0; i < Map[digits[idx]].size(); i++){
			dfs(digits, idx + 1, v, result + Map[digits[idx]][i]);
		}
	}
};
