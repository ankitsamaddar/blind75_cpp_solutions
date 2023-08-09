// DATE: 28-July-2023
/* PROGRAM: 09_Array - 3Sum

https://leetcode.com/problems/3sum/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i
!= k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

*/
// @ankitsamaddar @July_2023
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    // a+b+c = 0 ; a!=b!=c
    // sort the array
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    // iterate the array
    for (int i = 0; i < nums.size(); i++) {
      // Skip duplicates for i
      if (i > 0 and nums[i] == nums[i - 1]) continue;

      int left  = i + 1;            // next element
      int right = nums.size() - 1;  // last element

      while (left < right) {
        // calculate possible 3sums using 2 pointers
        int c3sum = nums[i] + nums[left] + nums[right];

        if (c3sum > 0)
          right--;
        else if (c3sum < 0)
          left++;
        else {  // 3sum is 0 so save it
          result.push_back({nums[i], nums[left], nums[right]});
          left++;  // next element from left

          // skip all duplicates after next element from left
          while (nums[left] == nums[left - 1] and left < right) left++;
        }
      }
    }
    return result;
  }
};
int main() {
  int nums[] = {-1, 0, 1, 2, -1, -4};
  vector<int> v(nums, nums + sizeof(nums) / sizeof(int));
  Solution sol;
  vector<vector<int>> res = sol.threeSum(v);

  for (const auto &row : res) {
    for (int num : row) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
