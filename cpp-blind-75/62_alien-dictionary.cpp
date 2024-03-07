// cpp-blind-75/62_alien-dictionary.cpp
/**
 * Date  : 13-Aug-2023
 * Repo: https://github.com/ankitsamaddar/
 *
 * Problem   :  Alien Dictionary
 * Difficulty:  🔴Hard
 *
 * Leetcode 0269 :  🔒 https://leetcode.com/problems/alien-dictionary
 * Lintcode 0892 :  https://www.lintcode.com/problem/892
 */

class Solution {
  public:
  /**
   * @param words: a list of words
   * @return: a string which is correct order
   */
  string alienOrder(vector<string> &words) {
    string order = "";

    if (words.empty()) return order;  // Return empty string if words list is empty

    unordered_map<char, vector<char>> graph = build_graph(words);  // Build graph from words

    order = topological_sort(graph);  // Perform topological sort on the graph

    return order;
  }

private:
  // Function to build the graph
  unordered_map<char, vector<char>> build_graph(vector<string> &words) {
    unordered_map<char, vector<char>> graph;

    bool is_valid = true;

    int size = words.size();
    for (int pos = 0; pos < size; pos++) {
      // add character to the graph for current word (words[pos])
      // if not already in the graph
      for (auto c : words[pos]) {
        if (!graph.count(c))
          graph[c] = vector<char>{};  // Add character to graph if not already present
      }
      // at least one word left
      if (pos + 1 < size) {
        // Get edge between consecutive words
        pair<char, char> edge = get_edge(pos, words, is_valid);

        if (!is_valid) {
          graph.clear();  // Clear graph if not valid
          return graph;
        }

        if (!edge.first) continue;

        graph[edge.first].push_back(edge.second);  // Add edge to graph
      }
    }

    return graph;
  }

  // Function to get the edge between consecutive words
  pair<char, char> get_edge(int pos, vector<string> &words, bool &is_valid) {
    pair<char, char> edge;

    string prev = words[pos];
    string next = words[pos + 1];

    int p        = 0;
    int prev_len = prev.length();
    int next_len = next.length();
    while (p < prev_len && p < next_len) {
      // if character do not match add it to edge
      if (prev[p] != next[p]) {
        edge = make_pair(prev[p], next[p]);  // Edge found between characters of consecutive words
        break;
      } else {
        p++;
      }
    }

    if (p >= next_len && p < prev_len) {
      is_valid = false;  // Set validity flag if one word is prefix of another
    }

    return edge;
  }

  // Function to perform topological sort
  string topological_sort(unordered_map<char, vector<char>> &graph) {
    string order;

    if (graph.empty()) return order;

    unordered_map<char, int> indegrees = compute_indegrees(graph);  // Compute indegrees of nodes

    priority_queue<char, vector<char>, greater<char>> q;
    // Priority queue for storing nodes with zero indegree
    for (auto pair : indegrees) {
      if (pair.second == 0) {
        q.push(pair.first);  // Add nodes with zero indegree to the queue
      }
    }

    while (!q.empty()) {
      char current = q.top();
      q.pop();
      order += current;  // Append current node to the order

      for (auto next_char : graph[current]) {
        if (--indegrees[next_char] == 0) {
          q.push(next_char);  // Decrement indegree of adjacent nodes and add to queue if indegree
                              // becomes zero
        }
      }
    }
    // Return order if all nodes are visited,
    // else return empty string
    return order.length() == graph.size() ? order : "";
  }

  // Function to compute indegrees of nodes
  unordered_map<char, int> compute_indegrees(unordered_map<char, vector<char>> &graph) {
    unordered_map<char, int> indegrees;

    for (auto pair : graph) {
      if (!indegrees.count(pair.first)) indegrees[pair.first] = 0;
      for (auto next_char : pair.second) {
        indegrees[next_char]++;  // Increment indegree of adjacent nodes
      }
    }

    return indegrees;
  }
};
