// cpp-blind-75/67_longest-increasing-subsequence.cpp
/**
 * Date  : 14-Aug-2023
 * Repo: https://github.com/ankitsamaddar/
 *
 * Problem   :  Longest Increasing Subsequence
 * Difficulty:  🟡Medium
 *
 * Leetcode 0300 :  https://leetcode.com/problems/longest-increasing-subsequence
 * Lintcode 0076 :  https://www.lintcode.com/problem/76
 */

class Solution {
  public:
  int lengthOfLIS(vector<int>& nums) {
    int len = nums.size();
    vector<int> seqLen(len, 1);

    // for each element check to its right
    for (int i = len - 1; i >= 0; i--) {
      for (int j = i + 1; j < len; j++) {
        // if element[i] is less the element in the right
        // add to its sequence length
        if (nums[i] < nums[j]) {
          seqLen[i] = max(seqLen[i], 1 + seqLen[j]);
        }
      }
    }
    // return the maximum sequence length computed
    return *max_element(seqLen.begin(), seqLen.end());
  }
};
