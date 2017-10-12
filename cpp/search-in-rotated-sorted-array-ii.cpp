/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.
*/


/* O(logn ~ n) */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        auto left = 0;
        auto right = static_cast<int>(nums.size()) - 1;
        while (left <= right) {
          auto mid = (left + right) / 2;
          auto num_mid = nums[mid];
          auto num_left = nums[left];
          auto num_right = nums[right];

          if (nums[mid] == target)
            return true;
          else if (num_mid == num_left)
            ++left;
          else if (num_mid > target && target >= num_left
            || num_mid < num_left && (target < num_mid || target >= num_left)) {
            right = mid - 1;
          } else {
            left = mid + 1;
          }
        }

        return false;
    }
};
