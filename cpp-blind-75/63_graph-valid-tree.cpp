// cpp-blind-75/63_graph-valid-tree.cpp
/**
 * Date  : 13-Aug-2023
 * Repo: https://github.com/ankitsamaddar/
 *
 * Problem   :  Graph Valid Tree
 * Difficulty:  🟡Medium
 *
 * Leetcode 0261 :  🔒 https://leetcode.com/problems/graph-valid-tree
 * Lintcode 0178 :  https://www.lintcode.com/problem/178
 */

class Solution {
  public:
  /**
   * @param n: An integer
   * @param edges: a list of undirected edges
   * @return: true if it's a valid tree, or false
   */
  bool validTree(int n, vector<vector<int>>& edges) {
    if (n == 0) return true; // no nodes

    // create the adjacency list
    for (const auto& ed : edges) {
      adj[ed[0]].push_back(ed[1]);
      adj[ed[1]].push_back(ed[0]);
    }
    // do dfs traversal from node 0
    // and check visited nodes and equal to total nodes
    return dfs(0, -1) and n == visit.size();
  }

  private:
  // adjacency list of nodes with there edges
  map<int, vector<int>> adj;
  set<int> visit;

  bool dfs(int i, int prev) {
    // if node is already visited the graph contains cycle
    if (visit.count(i)) return false;
    // insert the node in the visited list
    visit.insert(i);
    // do dfs for the rest of the nodes
    for (int j : adj[i]) {
      // do not traverse node which we are at
      if (j == prev) continue;
      // dfs of adjacent node returns false
      if (!dfs(j, i)) return false;
    }
    return true;
  }
};
