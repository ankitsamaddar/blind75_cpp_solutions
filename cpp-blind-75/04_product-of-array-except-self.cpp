// DATE: 27-07-2023
/* PROGRAM: 04_Array - Product of Array Except Self

https://leetcode.com/problems/product-of-array-except-self/

Given an integer array nums, return an array answer such that answer[i] is equal to the product of
all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

*/
// @ankitsamaddar @2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());

        // Prefix product - product of all elements before i
        int prefix = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = prefix;  // Store prefix product
            prefix = prefix * nums[i];
        }

        // Postfix product - product of all elements after i
        int postfix = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i]  = res[i] * postfix;  // multiply postfix product to prefix product values
            postfix = postfix * nums[i];
        }

        return res;
    }
};

int main() {

	int nums[] = {1, 2, 3, 4};
	vector<int> v(nums, nums + sizeof(nums) / sizeof(int));
	Solution sol;
	vector<int> rem = sol.productExceptSelf(v);

	for (int val : rem) {
		cout << val << " ";
	}
	return 0;
}
