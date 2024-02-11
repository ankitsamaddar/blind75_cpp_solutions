// cpp-blind-75/70_combination-sum.cpp
/**
 * Date  : 14-Aug-2023
 * Repo  : https://github.com/ankitsamaddar/
 *
 * Problem   :  Combination Sum
 * Difficulty:  🟡Medium
 *
 * Leetcode 0039 :  https://leetcode.com/problems/combination-sum
 * Lintcode 0135 :  https://www.lintcode.com/problem/135
 */

class Solution {
  public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // call dfs to do sum
    dfs(0, {}, 0, target, candidates);
    return res;
  }

  private:
  vector<vector<int>> res;

  void dfs(int i, vector<int> cur, int total, int target, vector<int>& candidates) {
    sort(candidates.begin(), candidates.end());

    // if total is equal to target
    // push the current combination array
    if (total == target) {
      res.push_back(cur);
      return;
    }

    // do dfs for the numbers starting at i
    for (int j = i; j < candidates.size(); j++) {
      // break if adding current number to total exceeds target
      if (total + candidates[j] > target) break;

      // push the current number and do sum using dfs
      cur.push_back(candidates[j]);
      int sum = total + candidates[j];
      dfs(j, cur, sum, target, candidates);
      // pop out if returned
      cur.pop_back();
    }
  }
};
