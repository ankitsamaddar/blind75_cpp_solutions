// DATE: 17-07-2023
/* PROGRAM: 44_Sub-Matrix Sum Query_std

Problem Statement:
Given a matrix consisting of integers, write a C++ program to answer queries on the matrix of type; i.e., sum the elements in the sub-matrix with top-left corner and bottom-right corner. The program should take the dimensions of the matrix, the matrix elements, and the number of queries as input. For each query, the program should take the top-left and bottom-right indices of the sub-matrix and print the sum of the sub-matrix.

Input Format:
The first line of input contains two integers n and m, representing the number of rows and columns of the matrix, respectively.
The next n lines contain m integers each, representing the elements of the matrix.
The next line contains a single integer q, representing the number of queries.
The next q lines contain four space-separated integers TL_i, TL_j, BR_i, and BR_j, respectively, representing the top-left and bottom-right indices of the sub-matrix for each query.

Output Format:
For each query, the program should print a single integer, i.e., the sum of the sub-matrix as described in the problem.

SAMPLE INPUT:
5 5
1 4 7 3 2
3 4 2 5 9
6 1 6 2 1
2 5 8 7 6
3 6 9 8 3
3
1 1 4 3
2 2 4 4
0 1 4 3

SAMPLE OUTPUT:
63
50
77

EXPLANATION
- sum of all elements of the sub-matrix
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;

void calculatePrefixSum(int** arr, int n, int m) {
	// Calculating prefix sum for every row
	for (int row = 0; row < n; row++) {
		for (int col = 1; col < m; col++) {
			arr[row][col] += arr[row][col - 1];
		}
	}
	// Calculating prefix sum for every column
	for (int col = 0; col < m; col++) {
		for (int row = 1; row < n; row++) {
			arr[row][col] += arr[row - 1][col];
		}
	}
}

int subMatrixQuery(int** arr, int n, int m, int li, int lj, int bi, int bj) {
	int subMatSum = 0;
	subMatSum += arr[bi][bj];
	// conditionals to check for if li and lj are not less than 0
	if (li > 0)
		subMatSum -= arr[li - 1][bj];
	if (lj > 0)
		subMatSum -= arr[bi][lj - 1];
	if (li > 0 && lj > 0)
		subMatSum += arr[li - 1][lj - 1];
	return subMatSum;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, q = 0;
	cin >> n >> m;
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	calculatePrefixSum(arr, n, m);
	cin >> q;  // no of sub-matrix queries
	int TL_i, TL_j, BR_i, BR_j = 0;
	for (int i = 1; i <= q; i++) {
		cin >> TL_i >> TL_j >> BR_i >> BR_j;
		cout << subMatrixQuery(arr, n, m, TL_i, TL_j, BR_i, BR_j) << endl;
	}
	return 0;
}
