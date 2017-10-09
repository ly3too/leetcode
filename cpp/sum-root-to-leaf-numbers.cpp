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
    int sumNumbers(TreeNode* root) {
        return sum_numbers_recur(root, 0);
    }
private:
    int sum_numbers_recur(TreeNode* root, int pa_sum) {
        if (!root)
            return 0;

        auto cur_sum = pa_sum * 10 + root -> val;

        if (!root -> left && !root -> right)
            return cur_sum

        return sum_numbers_recur(root -> left, cur_sum) + sum_numbers_recur(root -> right, cur_sum);
    }
};
