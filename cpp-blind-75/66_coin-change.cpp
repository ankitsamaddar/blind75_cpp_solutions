// cpp-blind-75/66_coin-change.cpp
/**
 * Date  : 14-Aug-2023
 * Repo: https://github.com/ankitsamaddar/
 *
 * Problem   :  Coin Change
 * Difficulty:  🟡Medium
 *
 * Leetcode 0322 :  https://leetcode.com/problems/coin-change
 * Lintcode 0669 :  https://www.lintcode.com/problem/669
 */

class Solution {
  public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    // count the change for each amount
    for (int a = 1; a <= amount; a++) {
      for (int c : coins) {
        if (a - c >= 0) {
          dp[a] = min(dp[a], 1 + dp[a - c]);
        }
      }
    }
    // return -1 if dp[amount] = amount + 1 that was initialized
    return dp[amount] != amount + 1 ? dp[amount] : -1;
  }
};
