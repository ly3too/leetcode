/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/

/* BST solution O(nlog(n)), O(n) */
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        BSTnode* root = nullptr;
        vector<int> count(nums.size());

        for (int i=nums.size()-1; i>=0; --i) {
            count[i] = insert_count(root, nums[i]);
        }

        return count;
    }
private:
    struct BSTnode{
        int val;
        int count;
        BSTnode* left;
        BSTnode* right;
        BSTnode(int val) : val{val}, count{0}, left{nullptr}, right{nullptr} {}
    };

    int insert_count(BSTnode* &root, int val) {
        if (root == nullptr) {
            root = new BSTnode(val);
            return 0;
        }

        BSTnode* cur = root;
        int count = 0;
        while (cur) {
            if (val < cur -> val) {
                ++(cur -> count);
                if (cur -> left)
                    cur = cur -> left;
                else {
                    cur -> left = new BSTnode(val);
                    return count;
                }
            } else {
                if (val > cur -> val)
                    count += 1 + cur -> count;
                else
                    count += cur -> count;
                if (cur -> right){
                    cur = cur -> right;
                } else {
                    cur -> right = new BSTnode(val);
                    return count;
                }
            }
        }
    }
};
