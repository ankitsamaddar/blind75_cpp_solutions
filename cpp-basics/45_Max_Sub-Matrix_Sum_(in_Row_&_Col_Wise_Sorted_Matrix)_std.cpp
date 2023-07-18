// DATE: 18-07-2023
/* PROGRAM: 45_Max Sub-Matrix Sum (in Row & Col Wise Sorted Matrix)_std

Given a matrix mat[][] whose elements are sorted both row-wise and column-wise. The task is to find the maximum sum of any sub-matrix from the given matrix mat[][].

INPUT
5 5
1 4 7 3 2
3 4 2 5 9
6 1 6 2 1
2 5 8 7 6
3 6 9 8 3

OUTPUT
113

EXPLANATION
The sub matrix consisting of the largest sum possible using the prefix sum.
*/
// @ankitsamaddar @2023
#include <algorithm>
#include <iostream>
using namespace std;

int maxSumSubMatrix(int** arr, int n, int m) {
	// Col-wise add
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			arr[i][j] += arr[i][j + 1];
		}
	}
	// Row-wise add
	for (int j = m - 1; j >= 0; j--) {
		for (int i = n - 2; i >= 0; i--) {
			arr[i][j] += arr[i + 1][j];
		}
	}
	int maxSum = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			maxSum = max(maxSum, arr[i][j]);
		}
	}
	return maxSum;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m = 0;
	cin >> n >> m;
	int** mat = new int*[n];
	for (int i = 0; i < n; i++) {
		mat[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	cout << maxSumSubMatrix(mat, n, m);
	return 0;
}
