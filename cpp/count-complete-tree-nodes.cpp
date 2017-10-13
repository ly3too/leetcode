/*
Given a complete binary tree, count the number of nodes.
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
 /* O(log(n)^2) */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        auto left = root;
        auto right = root;
        auto left_cnt = 0;
        auto right_cnt = 0;
        while (left) {
            left = left -> left;
            ++left_cnt;
        }

        while (right) {
            right = right -> right;
            ++right_cnt;
        }

        if (left_cnt == right_cnt) {
            return pow(2, left_cnt) - 1;
        }

        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};

/* O(logn^2) */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        auto left = root;
        auto level = 0;
        while (left -> left) {
            left = left -> left;
            ++level;
        }

        auto res = pow(2, level) - 1;
        auto s = 0;
        auto e = res;
        while (s <= e) {
            auto mid = (s + e) / 2;
            if (exist(root, level, mid)) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return res + s;
    }

private:
    bool exist(TreeNode* root, int level, int cnt) {

        auto half_cnt = static_cast<int>(pow(2, level)) / 2;
        while (half_cnt && root) {
            if (cnt >= half_cnt) {
                root = root -> right;
                cnt -= half_cnt;

            } else {
                root = root -> left;
            }

            half_cnt >>= 1;
        }

        return root != nullptr;
    }
};
