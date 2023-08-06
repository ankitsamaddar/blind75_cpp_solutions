// DATE: 06-Aug-2023
/* PROGRAM: 43_Tree - Maximum Depth of Binary Tree

https://leetcode.com/problems/maximum-depth-of-binary-tree/

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down
to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    /*
	// SOL1: RECURSIVE
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    */

    /*
	// SOL2: BREADTH FIRST SEARCH
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int level = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            level++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
        }
        return level;
    }

    */
	// SOL3: Depth First Search
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int level = 0, res = 0;
        stack<pair<TreeNode *, int>> sT;
        sT.push({root, 1});

        while (!sT.empty()) {
            TreeNode *node = sT.top().first;
            level          = sT.top().second;
            sT.pop();
            res = max(res, level);
            if (node->right != NULL) {
                sT.push(make_pair(node->right, level + 1));
            }
            if (node->left != NULL) {
                sT.push(make_pair(node->left, level + 1));
            }
        }
        return res;
    }
};

int main() {
    TreeNode *root     = new TreeNode(3);
    root->left         = new TreeNode(9);
    root->right        = new TreeNode(20);
    root->right->left  = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution sol;
    cout << sol.maxDepth(root) << endl;  // expected output: 3
    return 0;
}
