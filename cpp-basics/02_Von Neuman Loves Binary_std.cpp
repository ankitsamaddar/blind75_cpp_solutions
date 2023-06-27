// DATE: 27-06-2023
/* PROGRAM: 02_Von Neuman Loves Binary_std
https://www.hackerrank.com/contests/launchpad-1-winter-challenge/challenges/von-neuman-loves-binary

Given a binary number ,help Von Neuman to find out its decimal representation. For eg 000111 in binary is 7 in decimal.

Input Format
The first line contains N , the number of binary numbers. Next N lines contain N integers each representing binary represenation of number.

Constraints
N<=1000 Digits in binary representation is <=16.

Output Format
N lines,each containing a decimal equivalent of the binary number.

Sample Input
4
101
1111
00110
111111

Sample Output
5
15
6
63

*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
	cin >> N;
    int arr[N];
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	for (int i = 0; i<N; i++) {
		int bin = arr[i];
		int num = 0;
		int pow = 1;
		while (bin>0) {
			num+=((bin%10)*pow);
			bin=bin/10;
			pow*=2;
		}
		cout<<num<<endl;
	}
    return 0;
}
