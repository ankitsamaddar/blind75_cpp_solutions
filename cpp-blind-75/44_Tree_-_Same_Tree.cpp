// DATE: 07-Aug-2023
/* PROGRAM: 44_Tree - Same Tree

https://leetcode.com/problems/same-tree/

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the
same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false


*/
// @ankitsamaddar @Aug_2023
#include <iostream>
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p || !q) {
            return p == q;
        }
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    TreeNode *p = new TreeNode(1);
    p->left     = new TreeNode(2);
    p->right    = new TreeNode(3);
    TreeNode *q = new TreeNode(1);
    q->left     = new TreeNode(2);
    q->right    = new TreeNode(3);

	Solution sol;
	cout<<boolalpha<<sol.isSameTree(p, q)<<endl; // Expected : true
    return 0;
}
