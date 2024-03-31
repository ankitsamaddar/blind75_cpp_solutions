// DATE: 05-Aug-2023
/* PROGRAM: 29_String - Valid Anagram


Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
	public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) return false;
		vector<int> cntS(128);
		vector<int> cntT(128);
		for (int i = 0; i < s.length(); i++) {
			cntS[s[i]] += 1;
			cntT[t[i]] += 1;
		}
		for (char a : t) {
			if (cntS[a] != cntT[a]) return false;
		}
		return true;
	}
};

int main() {
	string s = "anagram", t = "nagaram";
	Solution sol;
	 cout << boolalpha << sol.isAnagram(s, t) << endl;
	return 0;
}
