/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur_path;
        pathSum_recur(root, res, cur_path, sum);
        return res;
    }
private:
    void pathSum_recur(TreeNode* root, vector<vector<int>> &res, vector<int> &cur_path, int sum) {
        if (!root)
            return;

        cur_path.emplace_back(root -> val);
        if (root -> left == nullptr && root -> right == nullptr && root -> val == sum) {
            res.emplace_back(cur_path);
            cur_path.pop_back();
            return;
        }

        if (root -> left) {
            pathSum_recur(root->left, res, cur_path, sum-root->val);
        }
        if (root -> right) {
            pathSum_recur(root->right, res, cur_path, sum-root->val);
        }

        cur_path.pop_back();
        return;
    }
};
