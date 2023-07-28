// DATE: 28-July-2023
/* PROGRAM: 13_Binary - Counting Bits

https://leetcode.com/problems/counting-bits/

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i]
is the number of 1's in the binary representation of i.

Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	vector<int> countBits(int n) {
		vector<int> dp(n + 1, 0);
		int offset = 1;
		for (int i = 1; i <= n; i++) {
			if (offset * 2 == i) { // To check if number is multiple of 2 (2,4,8,16,..)
				offset = i;		   // Set offset as current number
			}
			dp[i] = 1 + dp[i - offset]; // dp array stores all the 1 counts for every number
										// which is then used to calculate for the other numbers
		}
		return dp;
	}
};

int main() {
	int n = 3;
	Solution sol;
	vector<int> res = sol.countBits(n);
	for (int val : res) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
