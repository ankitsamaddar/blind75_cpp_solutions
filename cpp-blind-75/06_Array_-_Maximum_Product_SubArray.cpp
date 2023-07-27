// DATE: 28-July-2023
/* PROGRAM: 06_Array - Maximum Product SubArray

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
// @ankitsamaddar @July_2023
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
	int maxProduct(vector<int> &nums) {
		int res = INT_MIN;
		int curMin = 1, curMax = 1, tmp = 0;
		bool zeroPresent = false;
		for (int n : nums) {
			if (n == 0) {
				curMin = 1;
				curMax = 1;
				zeroPresent = true;
				continue;
			}

			tmp = curMax * n;
			curMax = max({n * curMax, n * curMin, n});
			curMin = min({tmp, n * curMin, n});
			res = max(res, curMax);
		}
		if (zeroPresent)
			return max(res, 0);
		return res;
	}
};

int main() {
	int nums[] = {-2, 0, -1};
	vector<int> v(nums, nums + sizeof(nums) / sizeof(int));
	Solution sol;
	int result = sol.maxProduct(v);
	cout << result << endl;
	return 0;
}
