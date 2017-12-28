/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        auto n = nums.size();
        if (n == 0)
            return 0;
        if (ns == 1)
            return nums[0];
        return max(rob_help(nums, 0, n-2), rob_hep(nums, 1, n-1));
    }

private:
    int rob_help(vector<int>& nums, int s, int e) {
        auto max_i1 = 0; // rob i-1
        auto max_i2 = 0; // rob i-2
        auto max_i = 0; // rob i
        for (int i=s; i <= e; ++i) {
            max_i = max(max_i1, max_i2 + nums[i]);
            max_i2 = max_i1;
            max_i1 = max_i;
        }
        return max_i;
    }
};
