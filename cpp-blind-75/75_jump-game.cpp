// cpp-blind-75/75_jump-game.cpp
/**
 * Date  : 15-Aug-2023
 * Repo  : https://github.com/ankitsamaddar/
 *
 * Problem   :  Jump Game
 * Difficulty:  🟡Medium
 *
 * Leetcode 0055 :  https://leetcode.com/problems/jump-game
 * Lintcode 0116 :  https://www.lintcode.com/problem/116
 */

class Solution {
  public:
  bool canJump(vector<int>& nums) {
    int i = 0;  // i to iterate nums
    int r = 0;  // r will track the maxium reachable index
    // iterate the array till reachable index is less than r
    for (; i < nums.size() && i <= r; i++) {
      // r is index form current num
      r = max(r, i + nums[i]);
    }
    // if i is equal to array size, i.e
    // all elements visited
    return i == nums.size();
  }
};
