/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

/* O(log(n) ~ O(n)) */
class Solution {
public:
    int findMin(vector<int>& nums) {
        auto left = 0;
        auto right = static_cast<int>(nums.size()) - 1;
        while (left < right && nums[left] >= nums[right]) {
          auto mid = (left + right) / 2;
          if (nums[mid] == nums[left])
            ++left;
          else if (nums[mid] < nums[left]) {
              right = mid;
          } else {
              left = mid + 1;
          }
        }

        return nums[left];

    }
};
