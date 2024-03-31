// DATE: 29-July-2023
/* PROGRAM: 19_Matrix - Word Search

https://leetcode.com/problems/word-search/

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

// Solution 2
class Solution {
  bool dfs(vector<vector<char>>& board, int i, int j, const char* word) {
    // this function will dfs search each element for match
    // uses recursion and then bactracks to get answer

    // word is a pointer to character array, so word+1 is the next charracter

    // word empty
    if (*word == '\0') return true;

    // limits reached
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != *word)
      return false;

    char c      = board[i][j];  // store current element
    board[i][j] = '\0';         // mark as visited

    // dfs in four directions
    // the recursion continues till last element of matrix
    // and backtracks to [i][j]
    // final result is stored in res
    bool res =
        // search right
        dfs(board, i + 1, j, word + 1) ||
        // search left
        dfs(board, i - 1, j, word + 1) ||
        // search down
        dfs(board, i, j + 1, word + 1) ||
        // search up
        dfs(board, i, j - 1, word + 1);

    // restore current element
    board[i][j] = c;

    return res;
  }

  public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (dfs(board, i, j, word.c_str())) return true;
      }
    }
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
