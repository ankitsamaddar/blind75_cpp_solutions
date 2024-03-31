// DATE: 07-Aug-2023
/* PROGRAM: 51_Tree - Validate Binary Search Tree

https://leetcode.com/problems/validate-binary-search-tree/

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

*/
// @ankitsamaddar @Aug_2023
#include <ios>
#include <iostream>
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

class Solution {
    public:
    bool isValidBST(TreeNode* root) { return valid(root, nullptr, nullptr); }

    bool valid(TreeNode* node, TreeNode* leftNode, TreeNode* rightNode) {
        if (!node) {
            return true;
        }
        // Binary Search Tree: Root > Left and Root < Right
        // current node value should be greater than leftNode
        // current node value should be less than rightNode
        if ((leftNode && node->val <= leftNode->val) ||
            (rightNode && node->val >= rightNode->val)) {
            return false;
        }

        return valid(node->left, leftNode, node) && valid(node->right, node, rightNode);
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left     = new TreeNode(1);
    root->right    = new TreeNode(3);
	Solution sol;
	cout<<boolalpha<<sol.isValidBST(root);
    return 0;
}
