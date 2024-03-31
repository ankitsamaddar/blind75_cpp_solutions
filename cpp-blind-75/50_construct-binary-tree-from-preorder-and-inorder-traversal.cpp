// DATE: 07-Aug-2023
/* PROGRAM: 50_Tree - Construct Binary Tree from Preorder and In-order Traversal

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

Given two integer arrays preorder and in-order where preorder is the preorder traversal of a binary
tree and in-order is the in-order traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], in-order = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], in-order = [-1]
Output: [-1]
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
class Solution {
    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart,
                     int inEnd) {
        if (preStart > preorder.size() - 1 || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inIndex = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->val) {
                inIndex = i;
            }
        }

        root->left = helper(preorder, inorder, preStart + 1, inStart, inIndex - 1);
        root->right =
            helper(preorder, inorder, preStart + inIndex - inStart + 1, inIndex + 1, inEnd);

        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node and node!=nullptr) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
    }
}
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};
    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);
	printTree(root);
    return 0;
}
