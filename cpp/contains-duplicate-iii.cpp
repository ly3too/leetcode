/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the
absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 0 || t < 0) {
            return false;
        }

        multiset<long long> bst;
        for (int i = 0; i < nums.size(); ++i) {
            // Only keep at most k elements.
            if (bst.size() > k) {
                bst.erase(bst.find(nums[i- k -1]));
            }

            // Every search costs time: O(logk). find if there is a num in bst, abs(num - nums[i]) <= t
            const auto it = bst.lower_bound(static_cast<long long>(nums[i]) - t);
            if (it == bst.cend() || (*it - nums[i]) > t) {
                // Not found.
                bst.emplace(nums[i]);
            } else {
                return true;
            }
        }

        return false;
    }
};
