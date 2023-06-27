// DATE: 27-06-2023
/* PROGRAM: 05_Finding Roots
Given a Number N and precision of root P
Find Square root of the number without using any predefined function

INPUT
10 5

OUTPUT
3.16227

*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
    int N,P;
    cin >> N>>P;
	double ans = 0;
	double inc = 1.0;
	for(int i =0;i<=P;i++){
		while (ans*ans<=N){
			ans+=inc;
		}
		ans-=inc; // last number whose root is less than N
		inc = inc/10; // set the next decimal place for precision
	}
	cout << ans;
    return 0;
}
