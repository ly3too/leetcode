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
    shared_ptr<TreeNode> restore(const vector<int> &preorder, const vector<int> &inorder) {
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

    void inorder_to_vector(const shared_ptr<TreeNode>& root, vector<int> &vec) {
        if (root == nullptr)
            return;

        inorder_to_vector(root->left, vec);

        vec.emplace_back(root->val);

        inorder_to_vector(root->right, vec);
    }

    void preorder_to_vector(const shared_ptr<TreeNode>& root, vector<int> &vec) {
        if (root == nullptr)
            return;

        vec.emplace_back(root->val);

        preorder_to_vector(root->left, vec);
        preorder_to_vector(root->right, vec);
    }

    void print_tree(const shared_ptr<TreeNode>& root, const int width=8) {
        int left_most = 0;
        vector<vector<pair<shared_ptr<TreeNode>, int>>> level_nodes; // nodes , x

        queue<pair<shared_ptr<TreeNode>, int>> que; //ptr, x, height
        que.push(make_pair(root, 0));

        while (!que.empty()) {
            vector<pair<shared_ptr<TreeNode>, int>> nodes;
            while (!que.empty()) {
                nodes.emplace_back(que.front());
                left_most = min(left_most, que.front().second);
                que.pop();
            }
            for (auto &node : nodes) {
                if (node.first) {
                    que.push(make_pair(node.first->left, node.second-1));
                    que.push(make_pair(node.first->right, node.second+1));
                }
            }
            level_nodes.emplace_back(move(nodes));
        }

        for (auto &level : level_nodes) {

            int cur_x = left_most;
            for (auto &node : level) {
                while (cur_x++ < node.second) {
                    cout << setw(width) << "";
                }

                if (node.first) {
                    cout << setw(width) << node.first->val;
                } else {
                    cout << setw(width) << "*";
                }
            }
            cout << endl;

            // cout "/ \";
            cur_x = left_most;
            for (auto &node : level) {
                while (cur_x++ < node.second) {
                    cout << setw(width) << "";
                }

                if (node.first) {
                    cout << setw(width/2) << "/" << setw(width-width/2) << "";
                    cout << setw(width) << "\\";
                    ++cur_x;
                }
            }
            cout << endl;
        }

    }

private:
    int construct_tree(shared_ptr<TreeNode>& root, const vector<int> &preorder, const vector<int> &inorder, int i, int start, int end) {
        root = make_shared<TreeNode>(preorder[i]);
        if (start == end) {
            return i;
        }

        /* find current root in inorder */
        int mid;
        for (mid=start; mid <= end; ++mid) {
            if (inorder[mid] == preorder[i]) {
                break;
            }
        }

        if (mid > end) {
            throw invalid_argument{"vector content mismatch"};
        }

        if (mid > start) {
            i = construct_tree(root->left, preorder, inorder, i+1, start, mid-1);
        }
        if (mid < end) {
            i = construct_tree(root->right, preorder, inorder, i+1, mid+1, end);
        }

        return i;
    }
};

int main() {
    Solution so;
    vector<int> pre{1,2,4,7,3,5,6,8};
    vector<int> in{4,7,2,1,5,3,8,6};
    cout << "original pre: " << pre << endl;
    cout << "original in: " << in << endl;

    try {
        auto root = so.restore(pre, in);
        so.print_tree(root);
        vector<int> res;
        so.preorder_to_vector(root, res);
        cout << res << endl;
        res.clear();
        so.inorder_to_vector(root, res);
        cout << res << endl;
    } catch (exception &ex) {
        cout << ex.what() << endl;
    }

    try {
        in.pop_back();
        auto root = so.restore(pre, in);
    } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
    }

    try {
        in.push_back(9);
        auto root = so.restore(pre, in);
    } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
    }

    pre.clear();
    in.clear();
    auto root = so.restore(pre, in);
    if (!root) {
        cout << "nullptr" << endl;
    }
}
