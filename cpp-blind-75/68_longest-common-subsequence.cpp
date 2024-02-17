// cpp-blind-75/68_longest-common-subsequence.cpp
/**
 * Date  : 14-Aug-2023
 * Repo: https://github.com/ankitsamaddar/
 *
 * Problem   :  Longest Common Subsequence
 * Difficulty:  🟡Medium
 *
 * Leetcode 1143 :  https://leetcode.com/problems/longest-common-subsequence
 * Lintcode 0077 :  https://www.lintcode.com/problem/77
 */

class Solution {
  public:
  int longestCommonSubsequence(string text1, string text2) {

    // dp to compute the common subsequence
    // text1.length rows, text2.length columns initialized to 0
    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

    // loop over each character of text1 and text2 from end
    for (int i = text1.length() - 1; i >= 0; i--) {
      for (int j = text2.length() - 1; j >= 0; j--) {

        if (text1[i] == text2[j])
          dp[i][j] = 1 + dp[i + 1][j + 1];
        else
          // store the max subsequence in the current dp cell
          dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
    // contains the longest common subsequence
    return dp[0][0];
  }
};
