/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
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
    vector<TreeNode*> generateTrees(int n) {
        if (n<1)
            return {};
        return generateTrees_recur(1, n);
    }

private:
    vector<TreeNode*> generateTrees_recur(int start, int end) {
        if (start > end)
            return {nullptr};

        vector<TreeNode*> res;
        for (int i=start; i <= end; ++i) {
            auto left_sub_trees = generateTrees_recur(start, i-1);
            auto right_sub_trees = generateTrees_recur(i+1, end);

            for (auto &left : left_sub_trees) {
                for (auto &right : right_sub_trees) {
                    auto new_node = new TreeNode(i);
                    new_node -> left = left;
                    new_node -> right = right;
                    res.emplace_back(new_node);
                }
            }

        }

        return res;
    }
};
