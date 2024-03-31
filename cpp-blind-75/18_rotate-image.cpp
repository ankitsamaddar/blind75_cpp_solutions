// DATE: 29-July-2023
/* PROGRAM: 18_Matrix - Rotate Image

https://leetcode.com/problems/rotate-image/

*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  void rotate(vector<vector<int>>& matrix) {
    // set the pointers
    int left = 0, right = matrix.size() - 1;

    // boundaries
    while (left < right) {
      for (int i = 0; i < right - left; i++) {
        // top and bottom pointers as left and right
        int top = left, bottom = right;

        // save the topLeft
        // matrix[0][0]
        int topLeft = matrix[top][left + i];

        // replace topLeft with bottomLeft
        // matrix[0][0] = matrix[2][0]
        matrix[top][left + i] = matrix[bottom - i][left];

        // replace bottomLeft with bottomRight
        // matrix[2][0] = matrix[2][2]
        matrix[bottom - i][left] = matrix[bottom][right - i];

        // replace bottomRight with topRight
        // matrix[2][2] = matrix[0][2]
        matrix[bottom][right - i] = matrix[top + i][right];

        // replace topRight with topLeft
        // matrix[0][2] = matrix[0][0]
        matrix[top + i][right] = topLeft;
      }
      right--;
      left++;
    }
  }
};

int main() {
	vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	Solution sol;
	sol.rotate(nums);
	for (auto row : nums) {
		for (int col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	return 0;
}
