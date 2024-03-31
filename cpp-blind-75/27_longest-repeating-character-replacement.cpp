// DATE: 03-Aug-2023
/* PROGRAM: 27_String - Longest Repeating Character Replacement

https://leetcode.com/problems/longest-repeating-character-replacement/

You are given a string s and an integer k. You can choose any character of the string and change it
to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing
the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".

The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achive this answer too.

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /* Slower as max_element operation is time consuming

      int characterReplacement(string s, int k) {
          vector<int> count(128);
          int res = 0, l = 0;
          for (int r = 0; r < s.length(); r++) {
              count[s[r]] += 1;

              while (((r - l + 1) - *max_element(count.begin(), count.end())) > k) {
                  count[s[l]] -= 1;
                  l++;
              }
              res = max(res, r - l + 1);
          }
          return res;
      }
    */
    // Faster using maxF to store the maximum frequency
    int characterReplacement(string s, int k) {
        vector<int> count(128);
        int res = 0, l = 0, maxF = 0;
        for (int r = 0; r < s.length(); r++) {
            count[s[r]] += 1;
            maxF = max(maxF, count[s[r]]);
            while (((r - l + 1) - maxF) > k) {
                count[s[l]] -= 1;
                l++;
            }
            // r-l+1 is the length of the substring from l to r
            res = max(res, r - l + 1);
        }
        return res;
    }
};

int main() {
    string s = "AABABBA";
    int k = 1;
    Solution sol;
    // Solution using Two pointer Approach
    cout << sol.characterReplacement(s, k) << endl;
    return 0;
}
