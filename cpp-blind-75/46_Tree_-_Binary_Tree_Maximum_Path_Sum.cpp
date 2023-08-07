// DATE: 07-Aug-2023
/* PROGRAM: 46_Tree - Binary Tree Maximum Path Sum

https://leetcode.com/problems/binary-tree-maximum-path-sum/

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has
an edge connecting them. A node can only appear in the sequence at most once. Note that the path
does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, int& res) {
        if (root == NULL) {
            return 0;
        }

        int leftMax  = max(0, dfs(root->left, res));
        int rightMax = max(0, dfs(root->right, res));

        res = max(res, root->val + leftMax + rightMax);

        return root->val + max(leftMax, rightMax);
    }
};

vector<int> parseInput(string input) {
    vector<int> result;
    int num       = 0;
    bool negative = false;
    for (char c : input) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '-') {
            negative = true;
        } else if (c == ',' || c == ']') {
            result.push_back(negative ? -num : num);
            num      = 0;
            negative = false;
        }
    }
    return result;
}

TreeNode* createTree(vector<int>& nums, int i) {
    if (i >= nums.size() || nums[i] == INT_MIN) {
        return NULL;
    }
    TreeNode* root = new TreeNode(nums[i]);
    root->left     = createTree(nums, 2 * i + 1);
    root->right    = createTree(nums, 2 * i + 2);
    return root;
}

int main() {
    string input     = "[-10,9,20,null,null,15,7]";
    vector<int> nums = parseInput(input);
    TreeNode* root   = createTree(nums, 0);

    Solution sol;
    int maxPathSum = sol.maxPathSum(root);
    cout << maxPathSum << endl;  // expected output: 42

    return 0;
}
