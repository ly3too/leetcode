/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*/
#include "header.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        auto cur = 0;
        auto node = kth_smallest_recur(root, k, cur);
        return node -> val;
    }
private:
    TreeNode* kth_smallest_recur(TreeNode* root, int k, int &cur) {
        if (!root)
            return nullptr;

        if (root -> left) {
            auto left = kth_smallest_recur(root->left, k, cur);
            if (left)
                return left;
        }

        ++cur;
        if (cur == k)
            return root;

        return kth_smallest_recur(root -> right, k, cur);
   }
};

int main () {
    auto node1 = new TreeNode(2);
    node1 -> left = new TreeNode(1);
    node1 -> right = new TreeNode(3);

    cout << Solution{}.kthSmallest(node1, 2) << endl;
}
