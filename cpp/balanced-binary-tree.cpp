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
    bool isBalanced(TreeNode* root) {
        get_dept(root);
        return isbalanced;
    }
private:
    bool isbalanced = true;

    int get_dept(TreeNode* root) {
        if (!root)
            return 0;

        auto left_dept = get_dept(root -> left);
        auto right_dept = get_dept(root -> right);

        auto diff = left_dept - right_dept;
        if (diff < -1 || diff > 1)
            isbalanced = false;

        return max(left_dept, right_dept) + 1;
    }
};
