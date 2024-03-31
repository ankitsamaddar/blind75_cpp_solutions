// DATE: 05-Aug-2023
/* PROGRAM: 33_String - Longest Palindromic Substring

https://leetcode.com/problems/longest-palindromic-substring/

Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.length(); i++) {
            string s1 = palindrome(s, i, i);      // odd length sub-string
            string s2 = palindrome(s, i, i + 1);  // even length sub-string
                                                  // check till last element if even length
                                                  // sub-string
            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }
        return res;
    }

    string palindrome(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
};

int main() {
    string s = "babad";
    Solution sol;
    cout << sol.longestPalindrome(s);
    return 0;
}
