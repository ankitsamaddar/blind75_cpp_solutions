// DATE: 29-July-2023
/* PROGRAM: 18_Matrix - Rotate Image

https://leetcode.com/problems/rotate-image/

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.


Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	void rotate(vector<vector<int>> &matrix) {
		int l = 0, r = matrix.size() - 1;
		while (l < r) {
			for (int i = 0; i < r - l; i++) {
				int top = l, bottom = r;
				// save topLeft
				int topLeft = matrix[top][l + i];

				// move bottom left into top left
				matrix[top][l + i] = matrix[bottom - i][l];

				// move bottom right to bottom left
				matrix[bottom - i][l] = matrix[bottom][r - i];

				// move top right into bottom right
				matrix[bottom][r - i] = matrix[top + i][r];

				// move top left to top right
				matrix[top + i][r] = topLeft;
			}
			r--;
			l++;
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
