// DATE: 07-Aug-2023
/* PROGRAM: 48_Tree - Serialize and Deserialize Binary Tree

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

Serialization is the process of converting a data structure or object into a sequence of bits so
that it can be stored in a file or memory buffer, or transmitted across a network connection link to
be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your
serialization/deserialization algorithm should work. You just need to ensure that a binary tree can
be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do
not necessarily need to follow this format, so please be creative and come up with different
approaches yourself.

Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:
Input: root = []
Output: []

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Codec {
    public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        string ser;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                ser += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ser += "n,";
            }
        }
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }
        vector<string> nodes;
        string tmp;
        // parse string into array
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(tmp);
                tmp.clear();
            } else {
                tmp += c;
            }
        }
        nodes.push_back(tmp);

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        q.push(root);
        int i = 1;

        while (!q.empty() && i < nodes.size()) {
            TreeNode* node = q.front();
            q.pop();
            // add left node
            if (nodes[i] != "n") {
                node->left = new TreeNode(stoi(nodes[i]));
                q.push(node->left);
            }
            i++;
            // add right node
            if (nodes[i] != "n" and i < nodes.size()) {
                node->right = new TreeNode(stoi(nodes[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};



int main() {
    string input = "1,2,3,n,n,4,5";

    Codec sol;
    TreeNode* root = sol.deserialize(input);
	cout<<sol.serialize(root);

    return 0;
}
