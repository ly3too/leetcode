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
                right = mid;
            } else {
                left = mid + 1;
            }

            if (left == right && cnt>mid) {
                return left;
            }
        }

        return -1;
    }
};

/* same like linklist loop meeting point detection */
/* O(n), O(1) */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto fast = 0;
        auto slow = 0;
        const auto N = nums.size();
        while (fast < N && nums[fast] < N) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            /* found loop */
            if (fast == slow) {
                fast = 0;
                while (fast != slow) {
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return slow;
            }
        }

        return -1;
    }
};
