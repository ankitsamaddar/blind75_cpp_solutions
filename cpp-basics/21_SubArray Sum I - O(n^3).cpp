// DATE: 02-07-2023
/* PROGRAM: 21_SubArray Sum I - O(n^3)
Print the maximum sum of subarray and print the subarray for an array of N elements.
INPUT
10
-4 1 3 -2 6 2 -8 -9 4 7

OUTPUT
11
4 7

EXPLANATION
- It does this by scanning through the array and keeping track of the current sum of the subarray.
- Whenever the current sum becomes greater than the maximum sum encountered so far, it updates the maximum sum.
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
    int n,curSum,maxSum,left,right=0;
	int arr[100];
    cin >> n;
	for (int i = 0; i<n; i++) {
		cin>>arr[i];
	}
	for (int i =0; i<n; i++) {
		for (int j =i; j<n; j++) {
			curSum=0;
			for (int k = i; k<=j; k++) {
				curSum+=arr[k];
			}
			// cout<<curSum<<" ";
			if(curSum>maxSum){
				maxSum=curSum;
				left=i;
				right=j;
			}
		}
	}
	// print maximum sum
	cout<<maxSum<<endl;
	// print range of maximum sum subarray
	for (int i = left; i<=right; i++) {
		cout<<arr[i]<<" ";
	}
    return 0;
}
