// cpp-blind-75/72_house-robber-ii.cpp
/**
 * Date  : 14-Aug-2023
 * Repo  : https://github.com/ankitsamaddar/
 *
 * Problem   :  House Robber II
 * Difficulty:  🟡Medium
 *
 * Leetcode 0213 :  https://leetcode.com/problems/house-robber-ii
 * Lintcode 0534 :  https://www.lintcode.com/problem/534
 */

class Solution {
  public:
  int rob(vector<int>& nums) {
    // base case
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];

    // inline function calculate max that can be robbed
    // same as the house-robber program
    auto helper = [&](int s, int e) -> int {
      int rob1 = 0, rob2 = 0;

      for (int i = s; i <= e; i++) {
        int dp = max(rob1 + nums[i], rob2);
        rob1   = rob2;
        rob2   = dp;
      }

      return rob2;
    };

    return max(                      // find the max amount that can be robbed
        helper(0, nums.size() - 2),  // first house to 2nd last house
        helper(1, nums.size() - 1)   // second house to last house
    );
  }
};
