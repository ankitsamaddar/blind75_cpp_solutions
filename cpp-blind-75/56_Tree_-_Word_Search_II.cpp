// DATE: 08-Aug-2023
/* PROGRAM: 56_Tree - Word Search II

https://leetcode.com/problems/word-search-ii/

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are
horizontally or vertically neighboring. The same letter cell may not be used more than once in a
word.

Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words =
["oath","pea","eat","rain"] Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class TrieNode {
    public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() : isWord(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) delete children[i];
        }
    }

    // Trie Functions
    void addWord(string word) {
        TrieNode* cur = this;
        for (char c : word) {
            int idx = c - 'a';  // ASCII of a => 97
            if (!cur->children[idx]) {
                cur->children[idx] = new TrieNode();
            }

            cur = cur->children[idx];
        }
        cur->isWord = true;
    }
};

class Solution {
    private:
    int rows;
    int cols;
    unordered_set<string> res;

    // Implement DFS
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string word) {
        char ch = board[r][c];
        if (ch == '$') return;
        board[r][c] = '$';
        TrieNode* t = node->children[ch - 'a'];

        if (t) {
            string ss = word + ch;
            if (t->isWord) res.insert(ss);
            if (r < rows - 1) dfs(board, r + 1, c, t, ss);
            if (r > 0) dfs(board, r - 1, c, t, ss);
            if (c < cols - 1) dfs(board, r, c + 1, t, ss);
            if (c > 0) dfs(board, r, c - 1, t, ss);
        }
        board[r][c] = ch;
    }

    public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.size() == 0) return {};
        TrieNode root;
        for (string w : words) {
            root.addWord(w);
        }
        rows = board.size();
        cols = board[0].size();
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                dfs(board, r, c, &root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words  = {"oath", "pea", "eat", "rain"};
    vector<string> result = solution.findWords(board, words);

    cout << "Result: ";  // Result: eat oath

    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
