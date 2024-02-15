// cpp-blind-75/74_unique-paths.cpp
/**
 * Date  : 15-Aug-2023
 * Repo  : https://github.com/ankitsamaddar/
 *
 * Problem   :  Unique Paths
 * Difficulty:  🟡Medium
 *
 * Leetcode 0062 :  https://leetcode.com/problems/unique-paths
 * Lintcode 0114 :  https://www.lintcode.com/problem/114
 */

class Solution {
  public:
  int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);  // initialize with 1

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        // The number of unique paths to reach a cell is,
        // the sum of the number of unique paths to,
        // reach the cell above it and the cell to its left.
        dp[j] += dp[j - 1];
      }
    }
    // the la
    return dp[n - 1];
  }
};
