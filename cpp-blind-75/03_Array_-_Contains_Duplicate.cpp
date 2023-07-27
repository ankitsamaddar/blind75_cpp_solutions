// DATE: 27-07-2023
/* PROGRAM: 03_Array - Contains Duplicate

https://leetcode.com/problems/contains-duplicate/

Given an integer array nums, return true if any value appears at least twice in the array, and
return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

*/
// @ankitsamaddar @2023
#include <ios>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
	bool containsDuplicate(vector<int> &nums) {
		set<int> hashSet;
		for (int n : nums) {
			if (hashSet.count(n)) {
				return true;
			}
			hashSet.insert(n);
		}
		return false;
	}
};

int main() {

	int arr[] = {1, 2, 3, 1};
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	Solution sol;
	bool ret = sol.containsDuplicate(v);
	cout << boolalpha << ret << endl; // boolalpha to print the boolean value instead of
									  // numeric(0/1)
	return 0;
}
