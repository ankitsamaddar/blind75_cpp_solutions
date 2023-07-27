// DATE: 28-07-2023
/* PROGRAM: 05_Array - Maximum Product SubArray

https://leetcode.com/problems/maximum-product-subarray/

Given an integer array nums, find a sub-array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a sub-array.

*/
// @ankitsamaddar @2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	int maxSubArray(vector<int> &nums) {
		int curSum = 0;
		int maxSum = INT_MIN;
		for (auto cur : nums) {
			curSum = max(cur, curSum + cur);
			maxSum = max(curSum, maxSum);
		}
		return maxSum;
	}
};

int main() {
	int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> v(nums, nums + sizeof(nums) / sizeof(int));
	Solution sol;
	int result = sol.maxSubArray(v);
	cout << result << endl; // output: 6
	return 0;
}
