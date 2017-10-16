/*
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
*/

/* O(nlog(s)), s = sum of n */
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        int right = 0;
        for (auto &x : nums) {
            left = max(left, x);
            right += x;
        }

        while (left <= right) {
            auto mid = left + (right - left) / 2;
            if (can_split(nums, m, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool can_split(vector<int> &nums, int m, int sum) {
        auto cnt = 0;
        auto cur_sum = 0;
        for (auto &x : nums) {
            cur_sum += x;
            if (cur_sum > sum) {
                cur_sum = x;
                ++cnt;
            }
        }
        ++cnt;

        return cnt <= m;
    }
};
