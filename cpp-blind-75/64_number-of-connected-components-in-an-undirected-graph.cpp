// cpp-blind-75/64_number-of-connected-components-in-an-undirected-graph.cpp
/**
 * Date  : 13-Aug-2023
 * Repo: https://github.com/ankitsamaddar/
 *
 * Problem   :  Number of Connected Components in an Undirected Graph
 * Difficulty:  🟡Medium
 *
 * Leetcode 0323 :  🔒
 * https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph
 * Lintcode 3651 :  https://www.lintcode.com/problem/3651
 */

class Solution {
  public:
  int countComponents(int n, vector<vector<int>>& edges) {
    par.resize(n);
    rank.resize(n, 1);
    int count = n;

    // each node is initially its own parent
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }

    // for each node do union, and reduce the nodes count
    for (auto& edge : edges) {
      count -= union1(edge[0], edge[1]);
    }

    // return connected components
    return count;
  }

  private:
  vector<int> par;
  vector<int> rank;

  // find parent node
  int find(int n1) {
    int count = n1;

    while (count != par[count]) {
      par[count] = par[par[count]];
      count      = par[count];
    }

    return count;
  }

  // merge components
  int union1(int n1, int n2) {
    int p1 = find(n1);
    int p2 = find(n2);

    if (p1 == p2) {
      return 0;
    }
    // attach the smaller rank tree
    // under the root of the larger rank tree.
    if (rank[p2] > rank[p1]) {
      par[p1] = p2;
      rank[p2] += rank[p1];
    } else {
      par[p2] = p1;
      rank[p1] += rank[p2];
    }

    return 1;
  }
};
