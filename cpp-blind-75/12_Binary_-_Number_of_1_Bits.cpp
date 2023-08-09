// DATE: 28-July-2023
/* PROGRAM: 12_Binary - Number of 1 Bits

https://leetcode.com/problems/number-of-1-bits/
*/
// @ankitsamaddar @July_2023
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
      // bitwise AND with 1 will return 1 if last bit is 1
      // 1110001 & 0000001 = 1
      if (n & 1) count++;  // increment count if 1 encountered

      // right shift n by 1 to check next bit for 1
      n = n >> 1;
    }
    return count;
  }
};
int main() {
	uint32_t n = 0000000000000000000000000001011;
	Solution sol;
	cout << sol.hammingWeight(n) << endl;
	return 0;
}
