// DATE: 28-July-2023
/* PROGRAM: 08_Array - Search in Rotated Sorted Array

https://leetcode.com/problems/search-in-rotated-sorted-array/

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k
< nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0],
nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target
if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1

*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	int search(vector<int> &nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = (int)(left + right) / 2;
			if (target == nums[mid]) {
				return mid;
			}
			// left
			if (nums[left] <= nums[mid]) {
				if (target > nums[mid] || target < nums[left])
					left = mid + 1;
				else
					right = mid - 1;
			}
			// right
			else {
				if (target < nums[mid] || target > nums[right]) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
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
	cout << rem<<endl;
	return 0;
}
