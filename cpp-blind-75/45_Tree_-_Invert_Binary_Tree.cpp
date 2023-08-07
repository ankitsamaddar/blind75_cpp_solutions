// DATE: 07-Aug-2023
/* PROGRAM: 45_Tree - Invert Binary Tree

https://leetcode.com/problems/invert-binary-tree/

Given the root of a binary tree, invert the tree, and return its root.

Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
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

class Solution {
    public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* left  = root->left;
        TreeNode* right = root->right;
        root->left      = invertTree(right);
        root->right     = invertTree(left);
        return root;
    }
};

TreeNode* createTree(vector<int>& nums) {
    if (nums.empty()) {
        return NULL;
    }
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nums.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (nums[i] != INT_MIN) {
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        i++;
        if (i < nums.size() && nums[i] != INT_MIN) {
            node->right = new TreeNode(nums[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

string formatOutput(TreeNode* root) {
    string result = "[";
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node != NULL) {
            result += to_string(node->val);
            result += ",";
            q.push(node->left);
            q.push(node->right);
        }
    }
    result.pop_back();
    result += "]";
    return result;
}
int main() {
    vector<int> nums = {4, 2, 7, 1, 3, 6, 9};
    TreeNode* root   = createTree(nums);

    Solution sol;
    TreeNode* invertedRoot = sol.invertTree(root);

    string output = formatOutput(invertedRoot);
    cout << output << endl;  // expected output: [4,7,2,9,6,3,1]

    return 0;
}
