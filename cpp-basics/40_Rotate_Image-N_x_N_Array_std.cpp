// DATE: 16-07-2023
/* PROGRAM: 40_Rotate Image(N x N Array)_std

Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.

Constraints
N < 1000

Input Format
First line contains a single integer N. Next N lines contain N space separated
integers.

Output Format
Print N lines with N space separated integers of the rotated array.

Sample Input
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Sample Output
4 8 12 16
3 7 11 15
2 6 10 14
1 5 9 13

EXPLANATION

*/
// @ankitsamaddar @2023
#include <iostream>
#include <algorithm>
using namespace std;

void rotate(int arr[][100],int n){
	// reverse each row
	for (int row=0; row<n; row++) {
		int startCol=0;
		int endCol=n-1;
		while (startCol<endCol) {
			swap(arr[row][startCol++],arr[row][endCol--]);

		}
	}
	// to take transpose
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i<j) {
				swap(arr[i][j],arr[j][i]);
			}
		}
	}

}
void rotate_stl(int arr[][100],int n){
	for (int i=0; i<n; i++) {
		// reverse(start_container,end_container)
		reverse(arr[i],arr[i]+n);
	}
	// to take transpose
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i<j) {
				swap(arr[i][j],arr[j][i]);
			}
		}
	}
}

void display(int arr[][100], int n){
	for (int i=0; i<n; i++) {
		for (int j= 0; j<n; j++) {
			cout << arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n=0;
    cin >> n;
	int arr[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		cin>>arr[i][j];
		}
	}
	rotate_stl(arr, n);
	display(arr,n);
    return 0;
}
