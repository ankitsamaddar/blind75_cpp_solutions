// DATE: 28-July-2023
/* PROGRAM: 07_Array - Find Minimum in Rotated Sorted Array

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  int findMin(vector<int>& nums) {
    int minValue  = nums[0];
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
      if (nums[left] < nums[right]) {  // sorted in ascending
        minValue = min(minValue, nums[left]);
        break;
      }

      // Binary search

      int mid = (int)(left + right) / 2;
      minValue     = min(minValue, nums[mid]);  // mid value

      if (nums[mid] >= nums[left]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return minValue;
  }
};

int main() {
  int nums[] = {4, 5, 6, 7, 0, 1, 2};
  vector<int> v(nums, nums + sizeof(nums) / sizeof(int));
  Solution sol;
  int result = sol.findMin(v);
  cout << result << endl;
  return 0;
}
