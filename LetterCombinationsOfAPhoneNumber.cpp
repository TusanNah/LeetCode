//
//Given a string containing digits from 2 - 9 inclusive, return all possible letter combinations that the number could represent.Return the answer in any order.
//
//A mapping of digits to letters(just like on the telephone buttons) is given below.Note that 1 does not map to any letters.
//
//
//
//Example 1:
//
//Input: digits = "23"
//Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
//
//Example 2 :
//
//	Input : digits = ""
//	Output : []
//
//	Exa
//
//	mple 3 :
//
//	Input : digits = "2"
//	Output : ["a", "b", "c"]


class Solution {
public:
	void combinations(vector <string>& res, string& combination, string characters[], string digits, int index) {
		if (index == digits.size()) {
			res.push_back(combination);
			return;
		}
		//digits = "23"

		int digit = digits[index] - '0';
		int size = characters[digit].size();
		for (int i = 0; i < size; ++i) {
			combination[index] = characters[digit][i];
			//substring(1   )string& append(const string & str);
			//substring(2)	string& append(const string & str, size_t subpos, size_t sublen)
			combinations(res, combination, characters, digits, index + 1);
			combination[index] = ' ';
		}
	}
	vector<string> letterCombinations(string digits) {
		vector <string> res;
		if (digits.size() == 0) {
			res.resize(0);
			return res;
		}
		string characters[] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		string combination(digits.size(), ' ');
		combinations(res, combination, characters, digits, 0);
		return res;
	}
};
//Solution: create string array containing characters of every digit, then use backtracking.