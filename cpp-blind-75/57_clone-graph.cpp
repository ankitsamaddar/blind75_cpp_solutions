// cpp-blind-75/57_clone-graph.cpp
/**
 * Date  : 09-Aug-2023
 * Repo: https://github.com/ankitsamaddar/
 *
 * Problem   :  Clone Graph
 * Difficulty:  🟡Medium
 *
 * Leetcode 0133 :  https://leetcode.com/problems/clone-graph
 * Lintcode 0137 :  https://www.lintcode.com/problem/137
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
  public:
  Node* cloneGraph(Node* node) {
    if (!node) {
      return nullptr;
    }
    return clone(node);
  }

  private:
  // map the Node with clone Node
  unordered_map<Node*, Node*> oldToNew;

  Node* clone(Node* node) { // clone nodes recursively
    // already cloned
    if (oldToNew.count(node)) {
      return oldToNew[node];
    }

    Node* copy     = new Node(node->val);
    oldToNew[node] = copy; // map old node to copy

    // Clone each node->neighbors to copy
    for (Node* nei : node->neighbors) {
      copy->neighbors.push_back(clone(nei));
    }
    return copy;
  }
};
