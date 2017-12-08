/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.
*/

/* O(n*2^n), O(2^n) */
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size() < 1)
            return false;
        auto sum = 0;
        auto max_num = nums[0];
        for (auto num: nums) {
            sum += num;
            max_num = max(max_num, num);
        }
        if (sum % k || max_num > sum/k)
            return false;

        lookup.clear();
        target = sum / k;
        return partition_dfs(nums, 0, sum);

    }
private:
    unordered_map<int, bool> lookup;
    int target;
    bool partition_dfs(vector<int>& nums, const int used, const int left) {
        if (left == 0)
            return true;
        if (!lookup.count(used)) {
            auto cur_target = (left - 1) % target + 1;
            for (int i=0; i < nums.size(); ++i) {
                if (used & (1 << i) || nums[i] > cur_target)
                    continue;
                if (partition_dfs(nums, used | (1 << i), left - nums[i])) {
                    lookup[used] = true;
                    return true;
                }
            }
            lookup[used] = false;
        }

        return false;
    }

};
