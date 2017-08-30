/*
Given an array with n objects colored red, white or blue, sort them so that objects of
the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and
blue respectively.
*/

/* O(n), O(1) */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        constexpr int ref = 1;

        for (int i=0, j=0, k=static_cast<int>(nums.size())-1; j<=k;) {
            if (nums[j] < ref) {
                swap(nums[i++], nums[j++]);
            } else if (nums[j] > ref) {
                swap(nums[j], nums[k--]);
            } else {
                ++j;
            }
        }

    }
};
