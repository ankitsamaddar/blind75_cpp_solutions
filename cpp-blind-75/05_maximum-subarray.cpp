// DATE: 28-07-2023
/* PROGRAM: 05_Array - Maximum SubArray

https://leetcode.com/problems/maximum-subarray/

Given an integer array nums, find the sub-array with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The sub-array [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The sub-array [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The sub-array [5,4,-1,7,8] has the largest sum 23.
*/
// @ankitsamaddar @2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int sum    = 0;
        int maxSum = INT_MIN;

        for (int i : nums) {
            sum    = max(i, sum + i);   // max sum till i
            maxSum = max(sum, maxSum);  // max sum so far
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
