// DATE: 03-Aug-2023
/* PROGRAM: 28_String - Minimum Window Substring

https://leetcode.com/problems/minimum-window-substring/

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s
such that every character in t (including duplicates) is included in the window. If there is no such
substring, return the empty string "". The test cases will be generated such that the answer is
unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	string minWindow(string s, string t) {
		if (t == "") return "";
		vector<int> countT(128);  // keep track of Characters in t
		vector<int> window(128);  // to track and store the characters in the substring
		int have = 0;             // Characters count in current window
		int need = 0;             // Characters count in t

		for (char c : t) {  // Update the characters present in t
			countT[c] += 1;
		}
		for (int i = 0; i < 128; i++) {  // Update the characters count present in t
			if (countT[i] > 0) need++;
		}
		int res    = -1;       // left most window pointer
		int resLen = INT_MAX;  // length of valid window

		for (int l = 0, r = 0; r < s.length(); r++) {
			char c = s[r];
			window[c] += 1;
			if (countT[c] != 0 and (window[c] == countT[c])) {
				// check if current window character is in t then update have
				have++;
			}
			while (have == need) {  // the window has all characters of t
				if ((r - l + 1) < resLen) {
					res    = l;
					resLen = r - l + 1;
				}
				window[s[l]] -= 1;
				if (countT[s[l]] != 0 and window[s[l]] < countT[s[l]]) {
					// If count of s[r] in window is less than in t
					have--;  // decrement have
				}
				l++;  // increase left pointer
			}
		}
		// return if resLen not INT_MAX the substring else return ""
		return resLen != INT_MAX ? s.substr(res, resLen) : "";
	}
};

int main() {
	string s = "ADOBECODEBANC", t = "ABC";
	Solution sol;
	cout << sol.minWindow(s, t);
	return 0;
}
