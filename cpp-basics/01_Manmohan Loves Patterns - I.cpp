/* PROGRAM 01. Manmohan Loves Patterns - I
https://www.hackerrank.com/contests/launchpad-1-winter-challenge/challenges/manmohan-loves-patterns-i

Problem
Given N, help Manmohan to print pattern upto N lines. For eg For N=5 , following pattern will be printed.

1
11
111
1001
11111

Input Format

Single number N.

Constraints

N<=1000

Output Format

Pattern corresponding to N.

Sample Input
5

Sample Output
1
11
111
1001
11111
100001
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;

int main() {

    int N;
    cin >> N;
	if (N<=1000){
		for(int i = 1;i<=N;i++){
			for(int j = 1;j<=i;j++){
				if(i%2!=0||j==1||j==i) cout<<"1";
				else cout<<"0";
			}
			cout<<endl;
		}
	}
    return 0;
}
