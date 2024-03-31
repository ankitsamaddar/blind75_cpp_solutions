// DATE: 07-Aug-2023
/* PROGRAM: 52_Tree - Kth Smallest Element in a BST

https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed)
of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <stack>
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
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        stack<TreeNode*> stack;
        stack.push(root);
        TreeNode* cur = root->left;
        while (cur || !stack.empty()) {
            while (cur) {
                stack.push(cur);
                cur = cur->left;
            }
            cur = stack.top(), stack.pop();
            ;
            n++;
            if (n == k) {
                return cur->val;
            }
            cur = cur->right;
        }
        return 0;
    }
};

int main() {
    TreeNode* root    = new TreeNode(3);
    root->left        = new TreeNode(1);
    root->right       = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int k             = 1;
    Solution sol;
    cout << sol.kthSmallest(root, k);
    return 0;
}
