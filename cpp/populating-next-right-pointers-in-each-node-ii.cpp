/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/



struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};


class Solution {
public:
    void connect(TreeLinkNode *root) {
        auto head = root;
        while (head) {
            auto cur = head;
            head = nullptr;
            TreeLinkNode* prev = nullptr;

            while(cur) {
                if (cur -> left) {
                    if (prev)
                        prev -> next = cur -> left;
                    prev = cur -> left;

                    if (head == nullptr)
                        head = cur -> left;
                }

                if (cur -> right) {
                    if (prev)
                        prev -> next = cur -> right;
                    prev = cur -> right;
                    if (head == nullptr)
                        head = cur -> right;
                }

                cur = cur -> next;
            }
        }
    }
};

int main () {
    Solution{}.connect(nullptr);
}
