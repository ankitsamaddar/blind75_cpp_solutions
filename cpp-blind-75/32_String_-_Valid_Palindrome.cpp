// DATE: 05-Aug-2023
/* PROGRAM: 32_String - Valid Palindrome

https://leetcode.com/problems/valid-palindrome/

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and
removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric
characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/
// @ankitsamaddar @Aug_2023
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
	public:
	bool isPalindrome(string s) {
		int i = 0;
		int j = s.size() - 1;
		while (i < j) {
			if (!iswalnum(s[i])) {
				i++;
			} else if (!iswalnum(s[j])) {
				j--;
			} else {
				if (tolower(s[i]) != tolower(s[j])) return false;
				i++;
				j--;
			}
		}

		return true;
	}
};

int main() {
	string s = "A man, a plan, a canal: Panama";
	Solution sol;
	cout<<boolalpha<<sol.isPalindrome(s);
	return 0;
}
