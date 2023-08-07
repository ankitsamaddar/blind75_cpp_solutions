// DATE: 07-Aug-2023
/* PROGRAM: 49_Tree - Subtree of Another Tree

https://leetcode.com/problems/subtree-of-another-tree/

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with
the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's
descendants. The tree tree could also be considered as a subtree of itself.

Example 1:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false

*/
// @ankitsamaddar @Aug_2023
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (root == nullptr) return false;
        if (sameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool sameTree(TreeNode* s, TreeNode* t) {
        if (!s or !t) {
            return s == t;
        }
        return s->val == t->val and sameTree(s->left, t->left) and sameTree(s->right, t->right);
    }
};

int main() {
    TreeNode* root           = new TreeNode(3);
    root->left               = new TreeNode(4);
    root->right              = new TreeNode(5);
    root->left->left         = new TreeNode(1);
    root->left->right        = new TreeNode(2);
    root->right->left        = nullptr;
    root->right->right       = nullptr;
    root->left->left->left   = nullptr;
    root->left->left->right  = nullptr;
    root->left->right->left  = nullptr;
    root->left->right->right = nullptr;
	// subRoot
    TreeNode* subRoot        = new TreeNode(4);
    subRoot->left            = new TreeNode(1);
    subRoot->right           = new TreeNode(2);
    subRoot->left->left      = nullptr;
    subRoot->left->right     = nullptr;
    subRoot->right->left     = nullptr;
	
    subRoot->right->right    = nullptr;
    Solution sol;
    bool res = sol.isSubtree(root, subRoot);
    cout << boolalpha << res << endl;
    return 0;
}
