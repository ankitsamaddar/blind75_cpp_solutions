// DATE: 28-July-2023
/* PROGRAM: 14_Binary - Missing Number

https://leetcode.com/problems/missing-number/

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the
range that is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the
missing number in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the
missing number in the range since it does not appear in nums.

Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the
missing number in the range since it does not appear in nums.

*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	int missingNumber(vector<int> &nums) {
		int res = nums.size();
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			res += (i - nums[i]);
		}
		return res;
	}
};

int main() {
	int nums[] = {3, 0, 1};
	vector<int> v(nums, nums + sizeof(nums) / sizeof(int));
	Solution sol;
	cout<<sol.missingNumber(v);
	return 0;
}
