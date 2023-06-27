// DATE: 28-06-2023
/* PROGRAM: 08_Number Pattern II

Print the pattern of 0s and 1s for input N

INPUT
5

OUTPUT
0
10
010
1010
01010
101010

EXPLANATION
- For ith line print i numbers
- odd line start with 0, and value alternates btw 0 and 1
- even line start with 1, and value alternate btw 0 and 1
- print n lines

*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
	for(int i=1;i<=N;i++){
		int val = i%2==0?1:0;
		int a = i;
		while(a>0){
			cout<<val;
			val=1-val;
			a--;
		}
		cout<<endl;
	}

	return 0;
}
