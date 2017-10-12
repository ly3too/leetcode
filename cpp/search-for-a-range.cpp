/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto begin = lower_bound(nums.cbegin(), nums.cend(), target);
        auto end = upper_bound(nums.cbegin(), nums.cend(), target);
        if (begin != end && *begin == target)
          return {begin - nums.cbegin(), end - nums.cbegin() - 1};

        return {-1, -1};
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        auto begin = lower_bound(nums, target);
        auto end = upper_bound(nums, target);
        if (begin != end && nums[begin] == target)
          return {begin, end - 1};

        return {-1, -1};
    }

  private:
    int lower_bound(vector<int>& nums, int target) {
      auto s = 0;
      auto e = static_cast<int>(nums.size()) - 1;
      while (s <= e) {
        auto mid = (s + e) / 2;
        if (nums[mid] < target) {
          s = mid + 1;
        } else {
          e = mid - 1;
        }
      }

      return s;
    }

    int upper_bound(vector<int>& nums, int target) {
      auto s = 0;
      auto e = static_cast<int>(nums.size()) - 1;
      while (s <= e) {
        auto mid = (s + e) / 2;
        if (nums[mid] <= target) {
          s = mid + 1;
        } else {
          e = mid - 1;
        }
      }

      return s;
    }
};
