/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

/* Olog(n) */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto s = 0;
        auto e = static_cast<int>(nums.size());
        while (s < e) {
          auto mid = (s + e - 1) / 2;
          if (nums[mid] < target) {
            s = mid + 1;
          } else {
            e = mid;
          }
        }
        return s;
    }
};
