/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
 find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

/* binary search O(nlogn), O(1)*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto left = 1;
        auto right = static_cast<int>(nums.size());

        while (left <= right) {
            auto mid = (left + right) / 2;

            auto cnt = 0;
            for (auto &x : nums) {
                if (x <= mid) {
                    ++cnt;
                }
            }

            if (cnt > mid) {
                right = mid-1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
