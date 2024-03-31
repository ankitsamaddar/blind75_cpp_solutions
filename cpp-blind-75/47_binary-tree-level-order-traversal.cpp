// DATE: 07-Aug-2023
/* PROGRAM: 47_Tree - Binary Tree Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from
left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int qLen = q.size();
            vector<int> curLevel;
            for (int i = 0; i < qLen; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    curLevel.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (!curLevel.empty()) {
                ans.push_back(curLevel);
            }
        }
        return ans;
    }
};

vector<int> parseInput(string input) {
    vector<int> result;
    int num       = 0;
    bool negative = false;
    for (char c : input) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == 'n') {
            num = INT_MAX;

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
    if (i >= nums.size() || nums[i] == INT_MAX) {
        return NULL;
    }
    TreeNode* root = new TreeNode(nums[i]);
    root->left     = createTree(nums, 2 * i + 1);
    root->right    = createTree(nums, 2 * i + 2);
    return root;
}

string formatOutput(vector<vector<int>>& output) {
    string result = "[";
    for (auto& level : output) {
        result += "[";
        for (int i = 0; i < level.size(); i++) {
            result += to_string(level[i]);
            if (i < level.size() - 1) {
                result += ",";
            }
        }
        result += "]";
    }
    result += "]";
    return result;
}

int main() {
    string input     = "[3,9,20,null,null,15,7]";
    vector<int> nums = parseInput(input);
    TreeNode* root   = createTree(nums, 0);

    Solution sol;
    vector<vector<int>> output = sol.levelOrder(root);

    string formattedOutput = formatOutput(output);
    cout << formattedOutput << endl;  // expected output: [[3],[9,20],[15,7]]

    return 0;
}
