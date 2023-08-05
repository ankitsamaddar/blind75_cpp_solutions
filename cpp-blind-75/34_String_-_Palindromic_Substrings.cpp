// DATE: 05-Aug-2023
/* PROGRAM: 34_String - Palindromic Substrings

https://leetcode.com/problems/palindromic-substrings/

Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            // odd length
            res += countPalindrome(s, i, i);
            // even length
            res += countPalindrome(s, i, i + 1);
        }
        return res;
    }

    int countPalindrome(string s, int l, int r) {
        int res = 0;
        while (l >= 0 and r <= s.length() and (s[l] == s[r])) {
            res++;
            l--;
            r++;
        }
        return res;
    }
};

int main() {
    string s = "aaa";
    Solution sol;
    cout << sol.countSubstrings(s) << endl;
    return 0;
}
