/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightSideView_recur(root, res, 1);
        return res;
    }

private:
    void rightSideView_recur(TreeNode* root, vector<int> &res, int depth) {
        if (!root)
            return;

        if (res.size() < depth) {
            res.emplace_back(root -> val);
        }

        rightSideView_recur(root -> right, res, depth + 1);
        rightSideView_recur(root -> left, res, depth + 1);

        return;
    }
};
