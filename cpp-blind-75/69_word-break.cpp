// cpp-blind-75/69_word-break.cpp
/**
 * Date  : 14-Aug-2023
 * Repo: https://github.com/ankitsamaddar/
 *
 * Problem   :  Word Break
 * Difficulty:  🟡Medium
 *
 * Leetcode 0139 :  https://leetcode.com/problems/word-break
 * Lintcode 0107 :  https://www.lintcode.com/problem/107
 */

class Solution {
  public:
  bool wordBreak(string s, vector<string>& wordDict) {
    // dp of length string with all values false
    // this will store if each character is beginning of a word
    vector<bool> dp(s.length() + 1, false);

    dp[s.length()] = true;  // set last character true

    // iterate from the end of string
    for (int i = s.length() - 1; i >= 0; i--) {
      // for each character check if it can form a word
      for (string w : wordDict) {
        if (
            // if there can be a word length string starting at index i
            (i + w.length() <= s.length()) and
            // if the substring starting from i to words length is the word
            s.substr(i, w.length()) == w) {
          // this will only set the word true if
          // the last word end at the last character
          dp[i] = dp[i + w.length()];
        }
        if (dp[i]) {  // if character is already start of a word no need to check any more word
          break;
        }
      }
    }
    // the first character will be true if only all the previous characters were able to form a word
    return dp[0];
  }
};
