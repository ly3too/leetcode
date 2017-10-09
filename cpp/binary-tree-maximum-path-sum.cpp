/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /* O(n), O(h) */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;

        max_path_sum_recur(root);
        return max_sum;
    }

private:
    int max_sum = numeric_limits<int>::min();
    int max_path_sum_recur(TreeNode* root) {
        if (!root)
            return 0;
        auto left = max(0, max_path_sum_recur(root -> left));
        auto right = max(0, max_path_sum_recur(root -> right));
        max_sum = max(max_sum, left + right + root -> val);

        return max(left+root->val, right+root->val);
    }
};
