// DATE: 28-July-2023
/* PROGRAM: 11_Binary - Sum of Two Integers

https://leetcode.com/problems/sum-of-two-integers/

*/
// @ankitsamaddar @July_2023
#include <iostream>

using namespace std;

class Solution {
  public:
  int getSum(int a, int b) {
    while (b != 0) {  // continue till no carry left or b=0

      // bitwise AND to get carry of each bit where both bit=1
      unsigned int c = a & b;

      // bitwise XOR to find sum without carry where any one bit=1
      a = a ^ b;

      // carry is left shifted by one and stored in b
      // as in binary addition carry is always added to the next bit

      b = c << 1;  // carry added in next iteration
    }

    return a;  // answer stored in a after adding the carries
  }
};

int main() {
	int a = -1, b = -3;
	Solution sol;
	cout << sol.getSum(a, b) << endl;
	return 0;
}
