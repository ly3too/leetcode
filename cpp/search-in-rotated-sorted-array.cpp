/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto left = 0;
        auto right = static_cast<int>(nums.size() - 1);
        while (left <= right) {
          auto mid = (left + right) / 2;
          auto num_mid = nums[mid];
          auto num_left = nums[left];
          auto num_right = nums[right];

          if (nums[mid] == target)
            return mid;
          else if (num_mid > target && target >= num_left
            || num_mid < num_left && (target < num_mid || target >= num_left)) {
            right = mid - 1;
          } else {
            left = mid + 1;
          }
        }

        return -1;
    }
};
