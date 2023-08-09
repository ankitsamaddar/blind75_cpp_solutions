// DATE: 28-July-2023
/* PROGRAM: 15_Binary - Reverse Bits

https://leetcode.com/problems/reverse-bits/

*/
// @ankitsamaddar @July_2023
#include <bitset>
#include <cstdint>
#include <iostream>
using namespace std;

class Solution {
  public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {  // iterate for 32 bits
      // i = 1
      // 1010 >> i = 0101;  left shift by i to get it to LSB
      // 0101 & 1 = 0001 bitwise AND with 1 extracts the last bit

      // Shift the bit left i times to get it to LSB
      // bitwise AND with 1 to extract it
      int bit = (n >> i) & 1;

      // right shift bit to get to MSB
      // bitwise OR to add it to the result
      res = res | (bit << (31 - i));
    }

    return res;
  }
};

int main() {
  uint32_t n = 0b00000010100101000001111010011100;  // should add 0b to specify its a binary number
  Solution sol;
  uint32_t res = sol.reverseBits(n);
  cout << res << " " << bitset<32>(res) << endl;  // bitset to print in binary with 32 bits
  return 0;
}
