//Given a string s, find the length of the longest
//substring
//without repeating characters.
//
//
//
//Example 1:
//
//Input: s = "abcabcbb"
//Output : 3
//Explanation : The answer is "abc", with the length of 3.
//
//Example 2 :
//
//	Input : s = "bbbbb"
//	Output : 1
//	Explanation : The answer is "b", with the length of 1.
//
//	Example 3 :
//
//	Input : s = "pwwkew"
//	Output : 3
//	Explanation : The answer is "wke", with the length of 3.
//	Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 1)
			return 1;
		unordered_map <char, int> map;
		int left = 0;
		int right = 0;
		int maxGlobal = 0;
		while (right < s.size()) {
			if (map.count(s[right]) == 0) { //Not contain that character
				maxGlobal = max(maxGlobal, right - left + 1);
				map[s[right]] = right; //Key is s[right], value is right
				right++;
			}
			else { //Contain that character'
				while (left < map[s[right]]) {
					map.erase(s[left]);
					left++;
				}
				left = map[s[right]] + 1;
				map.erase(s[right]); //Update new position
			}
		}
		return maxGlobal;
	}
};

//Solution: use hash map to check duplicate, use two pointers left and right to iterate the array.
