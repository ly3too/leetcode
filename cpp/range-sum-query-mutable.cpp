/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
*/

#include "header.hpp"

/* Binary index tree, time: O(n), O(logn), O(logn); space: O(n) */
class NumArray {
public:
    NumArray(vector<int>&& nums) : nums_{move(nums)} {
        N = nums_.size();
        bit_ = vector<int>(N+1, 0);

        for (int i=1; i<=N; ++i) {
            bit_[i] = bit_[i-1]+nums_[i-1];
        }
        for (int i=N; i>0; --i) {
            bit_[i] -= bit_[i-(i&-i)];
        }
    }

    void update(int i, int val) {
        if (i<N) {
            update_add(i, val - nums_[i]);
            nums_[i] = val;
        }
    }

    int sumRange(int i, int j) {
        return sum(j) - sum(i-1);
    }

private:
    vector<int> bit_;
    vector<int> nums_;
    size_t N;

    void update_add(int i, int val) {
        ++i;
        while (i<=N) {
            bit_[i] += val;
            i += (i&-i);
        }
    }

    int sum(int i) {
        ++i;
        int sum = 0;
        while (i>0) {
            sum += bit_[i];
            i -= (i&-i);
        }

        return sum;
    }
};
