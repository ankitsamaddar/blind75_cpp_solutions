// cpp-blind-75/61_longest-consecutive-sequence.cpp
/**
 * Date  : 12-Aug-2023
 * Repo: https://github.com/ankitsamaddar/
 *
 * Problem   :  Longest Consecutive Sequence
 * Difficulty:  🟡Medium
 *
 * Leetcode 0128 :  https://leetcode.com/problems/longest-consecutive-sequence
 * Lintcode 0124 :  https://www.lintcode.com/problem/124
 */

class Solution {
  public:
  int longestConsecutive(vector<int>& nums) {
    set<int> numSet;
    // hash the all numbers in a set
    for (int n : nums) {
      numSet.insert(n);
    }
    int longest = 0, len = 0;

    for (int n : nums) {
      // If the previous number is not in the set
      // then it the starting number of a sequence
      if (!numSet.count(n - 1)) {
        len = 0;  // reset length
        // while next number is in set, increment length
        while (numSet.count(n + len)) {
          ++len;
        }
        // set longest
        longest = max(len, longest);
      }
    }
    return longest;
  }
};
