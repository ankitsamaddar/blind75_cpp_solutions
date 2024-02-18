// cpp-blind-75/59_pacific-atlantic-water-flow.cpp
/**
 * Date  : 12-Aug-2023
 * Repo: https://github.com/ankitsamaddar/
 *
 * Problem   :  Pacific Atlantic Water Flow
 * Difficulty:  🟡Medium
 *
 * Leetcode 0417 :  https://leetcode.com/problems/pacific-atlantic-water-flow
 * Lintcode 0778 :  https://www.lintcode.com/problem/778
 */

class Solution {
  public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    rows = heights.size();
    cols = heights[0].size();
    // set to keep track of cells that can reach Pacific/Atlantic
    unordered_set<int> pac;
    unordered_set<int> atl;
    // Hash the rows
    for (int c = 0; c < cols; c++) {
      int prevHeight = heights[0][c];
      dfs(0, c, pac, prevHeight, heights);                   // Pacific - first row
      dfs(rows - 1, c, atl, heights[rows - 1][c], heights);  // Atlantic - last row
    }
    // Hash the columns
    for (int r = 0; r < rows; r++) {
      dfs(r, 0, pac, heights[r][0], heights);                // Pacific - first column
      dfs(r, cols - 1, atl, heights[r][cols - 1], heights);  // Atlantic - last column
    }

    vector<vector<int>> res;
    // Iterate the matrix and store the cells that can reach both ocean
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (
            // check if cell can reach Pacific(does exist)
            pac.find(r * cols + c) != pac.end() &&
            // check if cell can reach Atlantic
            atl.find(r * cols + c) != atl.end()) {
          res.push_back({r, c});
        }
      }
    }
    return res;
  }

  private:
  int rows, cols;

  void dfs(int r, int c, unordered_set<int>& visit, int prevHeight, vector<vector<int>>& heights) {
    if (
        // Already visited
        (visit.count(r * cols + c)) ||
        // row and col within limits
        r < 0 || c < 0 || r == rows || c == cols ||
        // height is less than the side
        heights[r][c] < prevHeight) {
      return;
    }
    visit.insert(r * cols + c);
    // dfs in every direction
    dfs(r + 1, c, visit, heights[r][c], heights);
    dfs(r - 1, c, visit, heights[r][c], heights);
    dfs(r, c + 1, visit, heights[r][c], heights);
    dfs(r, c - 1, visit, heights[r][c], heights);
  }
};
