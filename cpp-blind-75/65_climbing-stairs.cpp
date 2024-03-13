// cpp-blind-75/65_climbing-stairs.cpp
/**
 * Date  : 13-Aug-2023
 * Repo: https://github.com/ankitsamaddar/
 *
 * Problem   :  Climbing Stairs
 * Difficulty:  🟢Easy
 *
 * Leetcode 0070 :  https://leetcode.com/problems/climbing-stairs
 * Lintcode 0111 :  https://www.lintcode.com/problem/111
 */

class Solution {
  public:
  int climbStairs(int n) {
    int oneStep = 1, twoStep = 1;
    // use previous two computed value to get the value
    for (int i = 0; i < n - 1; i++) {
      int tmp = oneStep;
      oneStep     = oneStep + twoStep;
      twoStep     = tmp;
    }
    return oneStep;
  }
};
