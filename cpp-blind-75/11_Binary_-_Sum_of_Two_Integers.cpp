// DATE: 28-July-2023
/* PROGRAM: 11_Binary - Sum of Two Integers

https://leetcode.com/problems/sum-of-two-integers/

Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = 2, b = 3
Output: 5

*/
// @ankitsamaddar @July_2023
#include <iostream>

using namespace std;

class Solution {
  public:
	int getSum(int a, int b) {
		while (b != 0) {
			unsigned int carry = (a & b); // using unsigned as leftShift not possible for -ve number
			a = a ^ b;
			b = carry << 1;
		}
		return a;
	}
};

int main() {
	int a = -1, b = -3;
	Solution sol;
	cout << sol.getSum(a, b) << endl;
	return 0;
}
