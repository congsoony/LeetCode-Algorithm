class Solution {
public:
	string intToRoman(int num) {
		unordered_map<int,string> tostring = {
			{ 1, "I" }, { 5, "V" }, { 10, "X" }, { 50, "L" }, { 100, "C" },
			{ 500, "D" }, { 1000, "M" },
			{ 4, "IV" }, { 9, "IX" }, { 40, "XL" }, { 90, "XC" }, { 400, "CD" }, { 900, "CM" }
		};
		map<int, string> tostring2 = {
			{ 1, "I" }, { 5, "V" }, { 10, "X" }, { 50, "L" }, { 100, "C" },
			{ 500, "D" }, { 1000, "M" }
		};

		string n = to_string(num);
		string res = "";
		for (int i = 0; i < n.size(); i++){
			int idx = n.size() - 1 - i;
			int number = (n[i]-'0')*pow(10, idx);
			
			if (tostring.count(number)){
				res += tostring[number];
			}
			else{
				for (auto it = tostring2.rbegin(); it != tostring2.rend(); it++){
					int cur = it->first;
					while (number >= cur){
						res += it->second;
						number -= it->first;
					}
				}
			}
		}
		return res;
	}
};
