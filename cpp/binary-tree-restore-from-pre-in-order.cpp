/* given the pre and in order of a binary tree, restore it;
*/

#include "header.hpp"

struct TreeNode {
    int val;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    shared_ptr<TreeNode> restore(vector<int> &preorder, vector<int> &inorder) {
        shared_ptr<TreeNode> root{nullptr};
        const int N = preorder.size();
        if (N != inorder.size()) {
            throw invalid_argument{"vector size mismach"};
        }

        if (N) {
            construct_tree(root, preorder, inorder, 0, 0, N-1);
        }

        return root;
    }

    void inorder_to_vector(shared_ptr<TreeNode>& root, vector<int> &vec) {
        if (root == nullptr)
            return;

        inorder_to_vector(root->left, vec);

        vec.emplace_back(root->val);

        inorder_to_vector(root->right, vec);
    }

    void preorder_to_vector(shared_ptr<TreeNode>& root, vector<int> &vec) {
        if (root == nullptr)
            return;

        vec.emplace_back(root->val);

        inorder_to_vector(root->left, vec);
        inorder_to_vector(root->right, vec);
    }

private:
    void construct_tree(shared_ptr<TreeNode>& root, vector<int> &preorder, vector<int> &inorder, int i, int start, int end) {
        root = make_shared<TreeNode>(preorder[i]);
        if (start == end) {
            return;
        }

        /* find current root in inorder */
        for (int mid=start; mid <= end; ++mid) {
            if (inorder[mid] == preorder[i]) {
                break;
            }
        }

        if (mid > start) {
            construct_tree(root->left, preorder, inorder, i++, start, mid-1);
        }
        if (mid < end) {
            construct_tree(root->right, preorder, inorder, i++, mid+1, end);
        }
    }
}

int main() {
    Solution so;
}
