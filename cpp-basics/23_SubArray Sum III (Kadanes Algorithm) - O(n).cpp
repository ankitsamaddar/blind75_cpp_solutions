// DATE: 02-07-2023
/* PROGRAM: 23_SubArray Sum III (Kadanes Algorithm) - O(n)

INPUT
10
-4 1 3 -2 14 1 -8 -9 4 5

OUTPUT
17

EXPLANATION
- find maximum subarray sum in O(n) using Kadane's Algorithm
– the subarray with negative sum is discarded (by assigning maxSum = 0 in code).
– we carry subarray till it gives positive sum.
- In Kadane's Algorithm, at each iteration, the algorithm updates curSum by adding the current element to it and checks if curSum is greater than maxSum.
- If curSum is greater than maxSum, then maxSum is updated to curSum. If curSum becomes negative, it is reset to zero, as a negative sum cannot be part of the maximum sum subarray.

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
		curSum+=arr[i];
		if(curSum<0){
			curSum=0;
		}
		if (curSum>maxSum) {
			maxSum=curSum;
		}
		// maxSum = max(curSum,maxSum);
	}
	// print maximum sum
	cout<<maxSum<<endl;
    return 0;
}
