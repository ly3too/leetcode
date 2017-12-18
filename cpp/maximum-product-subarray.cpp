/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto glob_max = nums[0];
        auto loc_min = 1;
        auto loc_max = 1;

        for (auto num : nums) {
            auto cur_min = min(num, min(num * loc_min, num * loc_max));
            loc_max = max(num, max(num * loc_min, num * loc_max));
            loc_min = cur_min;
            glob_max = max(glob_max, loc_max);
        }

        return glob_max;
    }
};
