// DATE: 27-06-2023
/* PROGRAM: 04_Number Pyramid Pattern I
Write the code to print the following pattern for N number of lines:
INPUT
5
OUTPUT
    1
   232
  34543
 4567654
567898765

EXPLANATION
for each i th line
1. Each line has N-i spaces
2. Number from i to i+(i-1)
3. Number from i+(i-2) to i in decreasing order

*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
	for(int i = 1;i<=N;i++){
		int pad = N-i;
		while(pad>0){
			cout<<" ";
			pad--;
		}
		for (int j = i;j<i+i;j++){
			cout<<j;
		}
		for (int j = i+i-2;j>=i;j--){
			cout<<j;
		}

		cout<<endl;
	}
    return 0;
}
