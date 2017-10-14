/*Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity? */

/* O(log(n)) */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;

        for (auto &x : nums) {
          auto it = lower_bound(LIS.begin(), LIS.end(), x);

          if (it == LIS.end()) {
              LIS.emplace_back(x);
          } else {
              *it = x;
          }
        }

        return LIS.size();
    }
};
