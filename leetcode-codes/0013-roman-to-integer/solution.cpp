class Solution {
public:
	int romanToInt(string s) {
		unordered_map<string, int> tonum = {
			{ "I", 1 }, { "V", 5 }, { "X", 10 }, { "L", 50 }, { "C", 100 },
			{ "C", 100 }, { "D", 500 }, { "M", 1000 }, 
			{ "IV", 4 }, { "IX", 9 }, { "XL", 40 }, { "XC", 90 }, { "CD", 400 }, { "CM", 900 }
		};

		int sum = 0;
		for (int i = 0; i < s.size(); i++){
			string num = s.substr(i, 2);
			if (num.size() == 2 && tonum.count(num)){
				sum += tonum[num];
				i++;
			}
			else{
				sum += tonum[s.substr(i, 1)];
			}
		}

		return sum;
	}
};
