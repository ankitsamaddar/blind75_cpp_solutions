// DATE: 28-06-2023
/* PROGRAM: 10_Factorial Trailing Zeroes LC-172
https://leetcode.com/problems/factorial-trailing-zeroes/
Given an integer n, return the number of trailing zeroes in n!.
Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0

Constraints:
0 <= n <= 104

EXPLANATION
- trailing zeros in factorial of a number occurs when multiplied by 10 (factors of 10 are 2 and 5)
- 2 occurs many times so we consider numbers which are multiples of 5
- So we can calculate number of time 10 occurs using the formula :
(100/5^1)+(100/5^2)+(100/5^3)+... = Number of zeros
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
// start of soln.
int findZeros(int n){
int ans=0;
for(int d = 5;n/d>=1;d*=5){
	ans+=n/d;
}
return ans;
}
//end of soln.
int main() {
    long long int N;
    cin >> N;
    cout << findZeros(N) << endl;
    return 0;
}
