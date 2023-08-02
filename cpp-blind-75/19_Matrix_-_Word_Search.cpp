// DATE: 29-July-2023
/* PROGRAM: 19_Matrix - Word Search

https://leetcode.com/problems/word-search/

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are
horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
	vector<vector<bool>> matched_ch; // keep track of the locations visited

	bool exist(vector<vector<char>> &board, string word) {
		int rows = board.size(), cols = board[0].size();
		matched_ch.resize(rows, vector<bool>(cols, false));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (word.at(0) == board[i][j] && searchWord(i, j, 0, board, word)) {
					return true;
				}
			}
		}
		return false;
	}

	bool searchWord(int i, int j, int index, vector<vector<char>> &board, string word) {
		if (index == word.length()) { // Word Found
			return true;
		}

		if ( // Boundary Cond.
			i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
			word.at(index) != board[i][j] || // Main Check
			matched_ch[i][j]				 // Index Already Visited
		) {
			return false;
		}

		matched_ch[i][j] = true;
		if( // Condition checking if any neighbour is the next letter
            searchWord(i+1,j,index+1,board,word) ||
            searchWord(i-1,j,index+1,board,word) ||
            searchWord(i,j+1,index+1,board,word) ||
            searchWord(i,j-1,index+1,board,word) ){
			return true;
		}
		matched_ch[i][j] = false;

		return false;
	}
};

int main() {
	vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	string word = "ABCCED";
	Solution sol;
	cout << boolalpha << sol.exist(board, word) << endl;

	return 0;
}
