#include "header.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* depth first search, O(n), O(h) */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out;
        if (root) {
            out += to_string(root->val);
            out += ',';
            out += serialize(root -> left);
            out += ',';
            out += serialize(root -> right);
            // out += ',';
        }

        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize(ss);
    }

private:
    TreeNode* deserialize(stringstream& ss) {
        string s;
        getline(ss, s, ',');
        TreeNode* root = nullptr;
        if (!s.empty()) {
            root  = new TreeNode(stoi(s));
            root -> left = deserialize(ss);
            root -> right = deserialize(ss);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    Codec coder;
    cout << coder.serialize(coder.deserialize("1,1,2,,3,,1,,,,")) << endl;
}
