/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
*/

/* virtual indexed reverse tri partition, O(nlog(n)), O(1) */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if (nums.size() <= 2)
            return;

        int mid = (nums.size()-1) / 2;
        auto ref = nums[mid];
        const auto N = (nums.size()/2 * 2) + 1; // odd number;
        auto indx = [&](int i){return (2*i+1) % N;}; // index conversion

        for (int i=0, j=0, n=nums.size()-1; j<=n; ) {
             if (nums[indx(j)] > ref) {
                swap(nums[indx(j++)], nums[indx(i++)]);

            } else if (nums[indx(j)] < ref) {
                swap(nums[indx(j)], nums[indx(n--)]);

            } else {
                ++j;
            }
        }

    }
};
