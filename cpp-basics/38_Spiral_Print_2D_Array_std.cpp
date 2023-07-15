// DATE: 15-07-2023
/* PROGRAM: 38_Spiral Print 2D Array_std
You are given an M x N integer matrix. Write a program to print the elements of
the matrix in spiral order. The spiral order starts from the top left corner of
the matrix and moves in a clockwise direction towards the center of the matrix.
Example:
INPUT:
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

OUTPUT:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

EXPLANATION: The elements of the matrix are printed in a spiral order starting
from the top left corner and moving in a clockwise direction towards the center
of the matrix. To solve this problem, we can use four loops to maintain the
spiral order, each for the top, right, bottom, and left corner of the matrix. We
can initialize variables to keep track of the top, bottom, left, and right
indices of the matrix. We can then use these variables to print the elements of
the matrix in the spiral order.

*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
void spiralPrint(int **arr, int n, int m) {
  int endRow = m - 1;
  int endCol = n - 1;
  int startRow = 0;
  int startCol = 0;

  while (startRow <= endRow and startCol <= endCol) {
    // Top row
    for (int i = startCol; i <= endCol; i++) {
      cout << arr[startRow][i] << " ";
    }
    startRow++;
    // Right column
    for (int i = startRow; i <= endRow; i++) {
      cout << arr[i][endCol] << " ";
    }
    endCol--;
    // Bottom Row
    if (endRow > startRow) {
      for (int i = endCol; i >= startCol; i--) {
        cout << arr[endRow][i] << " ";
      }
      endRow--;
    }
    // Left Column
    if (endCol > startCol) {
      for (int i = endRow; i >= startRow; i--) {
        cout << arr[i][startCol] << " ";
      }
      startCol++;
    }
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m = 0;
  cin >> n >> m;
  int **arr = new int *[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new int[m];
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  spiralPrint(arr, n, m);
  return 0;
}
