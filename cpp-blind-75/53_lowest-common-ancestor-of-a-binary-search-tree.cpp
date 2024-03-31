// DATE: 07-Aug-2023
/* PROGRAM: 53_Tree - Lowest Common Ancestor of BST

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in
the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two
nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to
be a descendant of itself).”

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to
the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;

        while (cur) {
            if ((p->val > cur->val) and (q->val > cur->val)) {
                cur = cur->right;
            } else if ((p->val < cur->val) and (q->val < cur->val)) {
                cur = cur->left;
            } else {
                break;
            }
        }
        return cur;
    }
};

int main() {
    TreeNode* root = new TreeNode(6);
    root->left     = new TreeNode(2);
    root->right    = new TreeNode(8);
    // left sub-tree
    root->left->left         = new TreeNode(0);
    root->left->right        = new TreeNode(4);
    root->left->right->left  = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    // right sub-tree
    root->right->left  = new TreeNode(7);
    root->right->right = new TreeNode(9);
    // p and q
    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(8);
    Solution sol;
    TreeNode* res = sol.lowestCommonAncestor(root, p, q);
    cout << res->val;  // Output: 6

    return 0;
}
