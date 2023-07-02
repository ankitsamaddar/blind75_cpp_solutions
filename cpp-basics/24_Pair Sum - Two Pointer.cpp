// DATE: 02-07-2023
/* PROGRAM: 24_Pair Sum - Two Pointer
Given a Sorted Array, Find Pair of Elements that sum to K input.
INPUT
15
OUTPUT
3 12
5 10

EXPLANATION

*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
	int arr[] = {1, 3, 5, 7, 10, 11, 12, 13};
    int n = sizeof(arr)/sizeof(int);
	int k,i,j,curSum=0;
	j=n-1;
    cin >> k;
    while (i<j) {
		curSum=arr[i]+arr[j];
		if (curSum>k) {
			j--;
		}
		else if (curSum<k) {
			i++;
		}
		else  {
			cout<<arr[i]<<" "<<arr[j]<<endl;
			j--;
			i++;
		}
	}
    return 0;
}
