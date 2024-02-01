// cpp-blind-75/71_house-robber.cpp
/**
 * Date  : 14-Aug-2023
 * Repo  : https://github.com/ankitsamaddar/
 *
 * Problem   :  House Robber
 * Difficulty:  🟡Medium
 *
 * Leetcode 0198 :  https://leetcode.com/problems/house-robber
 * Lintcode 0392 :  https://www.lintcode.com/problem/392
 */

class Solution {
  public:
  int rob(vector<int>& nums) {
    //
    int house1 = 0, house2 = 0;

    // [house1,house2,n,n+1,....]
    // if we rob house1 then we can only rob current, and so on
    for (int current : nums) {
      // max after robbing current house or max of previous two houses
      int curMax = max(current + house1, house2);
      // update to prev two houses
      house1   = house2;
      // update prev2 house as current max
      house2   = curMax;
    }

    return house2;
  }
};
