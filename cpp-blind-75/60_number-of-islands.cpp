// cpp-blind-75/60_number-of-islands.cpp
/**
 * Date  : 12-Aug-2023
 * Repo: https://github.com/ankitsamaddar/
 *
 * Problem   :  Number of Islands
 * Difficulty:  🟡Medium
 *
 * Leetcode 0200 :  https://leetcode.com/problems/number-of-islands
 * Lintcode 0433 :  https://www.lintcode.com/problem/433
 */

class Solution {
  public:
  int numIslands(vector<vector<char>>& grid) {
    // Base case
    if (grid.empty()) return 0;
    int row = grid.size();
    int col = grid[0].size();
    // keep track of visited cell
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    int count                           = 0;
    // define the four possible directions to move
    vector<pair<int, int>> directions   = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // Inline function to find Island
    function<void(int, int)> findIsland = [&](int x, int y) {
      visited[x][y] = true;
      // for each direction, move the next cell
      for (auto [dx, dy] : directions) {
        // set directions and do dfs in those directions
        int nx = x + dx, ny = y + dy;
        // do dfs if within bounds and not already visited
        if (0 <= nx && nx < row && 0 <= ny && ny < col && grid[nx][ny] == '1' && !visited[nx][ny]) {
          findIsland(nx, ny);
        }
      }
    };
    // for each cell do dfs
    // if cell is 1 and not already visited
    // it is a island so increase count
    for (int x = 0; x < row; ++x) {
      for (int y = 0; y < col; ++y) {
        if (grid[x][y] == '1' && !visited[x][y]) {
          ++count;
          findIsland(x, y);
        }
      }
    }
    return count;
  }
};
