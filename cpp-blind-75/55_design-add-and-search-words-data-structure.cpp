// DATE: 08-Aug-2023
/* PROGRAM: 55_Tree - Add and Search Word

https://leetcode.com/problems/add-and-search-word-data-structure-design/

Design a data structure that supports adding new words and finding if a string matches any
previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or
false otherwise. word may contain dots '.' where dots can be matched with any letter.

Example:
Input:
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]

Output:
[null,null,null,null,false,true,true,true]

Explanation:
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class tNode {
    public:
    unordered_map<char, tNode*> children;
    bool isWord = false;
};

class WordDictionary {
    public:
    tNode* root = new tNode();

    WordDictionary() {}

    void addWord(string word) {
        tNode* cur = root;
        for (char c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new tNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }

    bool search(string word) { return dfs(0, word, root); }

    private:
    bool dfs(int j, string word, tNode* node) {
        for (int i = j; i < word.length(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto it : node->children) {
                    if (dfs(i + 1, word, it.second)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (node->children.count(c) == 0) {
                    return false;
                }
                node = node->children[c];
            }
        }
        return node->isWord;
    }
};

int main() {
    WordDictionary dict;
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");
    cout << boolalpha << dict.search("pad") << endl;  // Output: 0 (false)
    cout << boolalpha << dict.search("bad") << endl;  // Output: 1 (true)
    cout << boolalpha << dict.search(".ad") << endl;  // Output: 1 (true)
    cout << boolalpha << dict.search("b..") << endl;  // Output: 1 (true)
    return 0;
}
