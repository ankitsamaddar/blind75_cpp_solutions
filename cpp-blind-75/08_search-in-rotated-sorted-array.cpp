// DATE: 28-July-2023
/* PROGRAM: 08_Array - Search in Rotated Sorted Array

https://leetcode.com/problems/search-in-rotated-sorted-array/

*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  int search(vector<int>& nums, int target) {
    // Two Pointers Approach - Binary Search""
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
      int mid = (int)(left + right) / 2;

      if (target == nums[mid]) return mid;  // target found at mid

      if (nums[left] <= nums[mid]) {  // left half sorted

        if (target > nums[mid] || target < nums[left])
          left = mid + 1;  // target not in left half so move left after mid
        else
          right = mid - 1;  // move right before mid
      } else {              // right half sorted

        if (target < nums[mid] || target > nums[right])
          right = mid - 1;  // target not in right half so move right before mid
        else
          left = mid + 1;  // move left after mid
      }
    }
    return -1;
  }
};

int main() {
  int nums[] = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  vector<int> v(nums, nums + sizeof(nums) / sizeof(int));
  Solution sol;
  int rem = sol.search(v, target);
  cout << rem << endl;
  return 0;
}
