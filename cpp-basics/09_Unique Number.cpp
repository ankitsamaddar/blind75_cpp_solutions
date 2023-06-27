// DATE: 28-06-2023
/* PROGRAM: 09_Unique Number
Given a list of numbers where every numbers occurs twice except one, find that unique number.
INPUT
7
3 2 3 5 6 5 2

OUTPUT
6

EXPLANATION
a ^ a = 0
b ^ b = 0
a ^ b ^ 6 ^ b ^ a = 6
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
    int N,num,ans = 0;
    cin >> N;
    for (int i = 0; i<N; i++) {
		cin >> num;
		ans = ans ^ num;
	}
	cout << ans;
    return 0;
}
