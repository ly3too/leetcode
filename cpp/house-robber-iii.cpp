/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
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
class Solution {
public:
    int rob(TreeNode* root) {
        auto res = rob_recur(root);
        return max(res.first, res.second);
    }

private:
    /* first reperent rob the root, second represent not rob the root */
    pair<int, int> rob_recur(TreeNode* root) {
        if (!root)
            return {0,0};
        auto left = rob_recur(root -> left);
        auto right = rob_recur(root -> right);
        return {root -> val + left.second + right.second, max(left.first, left.second) + max(right.first, right.second)};
    }
};
