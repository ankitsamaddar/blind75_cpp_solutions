// DATE: 28-July-2023
/* PROGRAM: 13_Binary - Counting Bits

https://leetcode.com/problems/counting-bits/
*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  vector<int> countBits(int n) {
    // using dp to solve
    vector<int> res(n + 1, 0);  // initialize with zeros

    for (int i = 1; i <= n; i++) {
      // i-1 flips bits from least significant 1 bit; 1100-1 = 1011
      // bitwise AND only returns both bits with 1; 101 & 100 = 100

      // i = 5 = 101 ; i & (i-1) = 101 & 100 = 100 = 4
      // res[5] = res[4] + 1 = 1+1 = 2

      // i = 12 = 1100; i & (i-1) = 1101 & 1011 = 1000 = 8
      // res[12] = res[8] + 1 = 1+1 = 2

      // use precomputed res[i&(i-1)] which stores number of 1s from the Most Significant Bit
      res[i] = res[i & (i - 1)] + 1;
    }
    return res;
  }
};

// Solution 2 - Faster
class Solution {
  public:
  vector<int> countBits(int n) {
    vector<int> res(n + 1);  // n+1 to include 0

    // res[i] will store no. of 1s bit in i
    for (int i = 1; i <= n; i++) {
      // use precomputed values of i/2
      // 13/2 = 6; 13%2 = 1
      // res [6] = 2 ; as 6 is 110
      // res[i/2] + i%2 = 2+1 = 3 ; 13 = 1101 in which 3 bits are 1
      res[i] = res[i / 2] + i % 2;
    }
    return res;
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
