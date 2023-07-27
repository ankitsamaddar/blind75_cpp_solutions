// DATE: 27-07-2023
/* PROGRAM: 01_Array - Two Sum

https://leetcode.com/problems/two-sum/

Given an array of integers nums and an integer target, return indices of the two numbers such that
they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element
twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

EXPLANATION

*/
// @ankitsamaddar @2023
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
  public:
	vector<int> twoSum(vector<int> &nums, int target) {
		int n = nums.size();
		map<int, int> preMap;
		for (int i = 0; i < n; i++) {
			int diff = target - nums[i];
			if (preMap.count(diff) > 0) {
				return {preMap[diff], i};
			}
			preMap[nums[i]] = i;
		}
		return {};
	}
};

int main() {

	int nums[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int target = 9;
	vector<int> v (nums, nums + sizeof(nums) / sizeof(int));
	Solution sol;
	vector<int> rem = sol.twoSum(v,target);

	for (int val : rem) {
		cout << val<<" ";
	}
	return 0;
}
