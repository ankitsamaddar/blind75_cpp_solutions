// DATE: 02-07-2023
/* PROGRAM: 22_SubArray Sum II - O(n^2)
Print the maximum sum of subarray and print the subarray for an array of N elements.
INPUT
10
-4 1 3 -2 6 2 -8 -9 4 5

OUTPUT
10
1 3 -2 6 2 

EXPLANATION
- using cumulative sum (precomputing) array to solve it in O(n^2)
- csum[i] = csum[i-1] + arr[i] . The calculated sum for each index denotes the cumulative sum for that index from the first index.
- curSum=cumSum[j] - cumSum[i-1]. Subtract the cumulative sum till i to find sum from i to j index.
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
    int n,curSum,maxSum,left,right=0;
	int arr[100],cumSum[100];
    cin >> n;
	cin>>arr[0];
	cumSum[0]=arr[0];
	for (int i = 1; i<n; i++) {
		cin>>arr[i];
		cumSum[i]=cumSum[i-1]+arr[i];
	}
	for (int i =0; i<n; i++) {
		for (int j =i; j<n; j++) {
			curSum=cumSum[j] - cumSum[i-1]; // subtract the cumulative sum till i to find sum from i to j index
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
