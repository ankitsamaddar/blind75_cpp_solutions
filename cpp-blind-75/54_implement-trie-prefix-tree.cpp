// DATE: 07-Aug-2023
/* PROGRAM: 54_Tree - Implement Trie (Prefix Tree)

https://leetcode.com/problems/implement-trie-prefix-tree/

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and
retrieve keys in a dataset of strings. There are various applications of this data structure, such
as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted
before), and false otherwise. boolean startsWith(String prefix) Returns true if there is a
previously inserted string word that has the prefix prefix, and false otherwise.

Example 1:
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    char c;
    bool isWord;
    Node* children[26];

    Node(char c) {
        this->c = c;
        isWord  = false;
        // initialise all as null
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    public:
    Node* root;

    Trie() { root = new Node('\0'); }

    void insert(string word) {
        Node* cur = root;
        for (int i = 0; i < word.length(); i++) {
            char c  = word.at(i);
            int idx = c - 'a';
            if (cur->children[idx] == NULL) {
                cur->children[idx] = new Node(c);
            }
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }

    bool search(string word) {
        Node* node = getNode(word);
        return node != nullptr && node->isWord;
    }

    bool startsWith(string prefix) {
        Node* node = getNode(prefix);
        return node != nullptr;
    }

    private:
    // helper function to check if word
    Node* getNode(string word) {
        Node* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) {
                return nullptr;
            }
            cur = cur->children[idx];
        }
        return cur;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << boolalpha << trie.search("apple") << endl;    // Output: 1 (true)
    cout << boolalpha << trie.search("app") << endl;      // Output: 0 (false)
    cout << boolalpha << trie.startsWith("app") << endl;  // Output: 1 (true)
    trie.insert("app");
    cout << boolalpha << trie.search("app") << endl;  // Output: 1 (true)
    return 0;
}
