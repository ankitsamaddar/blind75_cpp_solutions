// DATE: 03-Aug-2023
/* PROGRAM: 26_String - Longest Substring Without Repeating Characters

https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.

Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> charSet;
		int l = 0, ans = 0;
		for (int r = 0; r < s.length(); r++) {
			while (charSet.count(s[r])) {
				charSet.erase(s[l]);
				l++;
			}
			charSet.insert(s[r]);
			ans = max(ans, r - l + 1);
		}
		return ans;
	}
};

int main() {
	string s = "abcabcbb";
	Solution sol;
	cout<<sol.lengthOfLongestSubstring(s)<<endl;
	return 0;
}
