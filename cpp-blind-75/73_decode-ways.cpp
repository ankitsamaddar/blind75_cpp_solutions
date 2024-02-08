// cpp-blind-75/73_decode-ways.cpp
/**
 * Date  : 15-Aug-2023
 * Repo  : https://github.com/ankitsamaddar/
 *
 * Problem   :  Decode Ways
 * Difficulty:  🟡Medium
 *
 * Leetcode 0091 :  https://leetcode.com/problems/decode-ways
 * Lintcode 0512 :  https://www.lintcode.com/problem/512
 */

class Solution {
  public:
  int numDecodings(string s) {
    // string empty or starts with zero
    if (s.empty() || s[0] == '0') return 0;

    // dp to store ways to decode till index
    vector<int> dp(s.size() + 1);
    dp[0] = 1;
    dp[1] = 1;

    // we start from the second character
    // dp i+1 represents i of the string
    for (int i = 1; i < s.size(); i++) {
      // if s[i]='0' then it can only be decoded,
      // if prev character is 1 or 2
      if (s[i] == '0') {
        if (s[i - 1] == '1' || s[i - 1] == '2') {
          dp[i + 1] = dp[i - 1];
        } else
          return 0;
      }
      // if the number between 10 - 26, can be decoded two ways
      // dp[i] + dp[i-1]
      else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
        dp[i + 1] = dp[i] + dp[i - 1];
      }
      // only be decoded one way
      else
        dp[i + 1] = dp[i];
    }
    // last number will contain the total ways that it can be decoded
    return dp[s.size()];
  }
};
