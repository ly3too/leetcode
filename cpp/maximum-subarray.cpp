/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ele = numeric_limits<int>::min();
        int global_max = numeric_limits<int>::min();
        int local_max = 0;

        for (auto num : nums) {
            max_ele = max(max_ele, num);
            local_max = max(0, num + local_max); // only keep positive sum
            global_max = max(local_max, global_max);
        }

        if (max_ele < 0)
            return max_ele;
        else
            return global_max;
    }
};
