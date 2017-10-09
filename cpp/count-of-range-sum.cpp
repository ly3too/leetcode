/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
*/

#include "header.hpp"

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        sums = move(vector<long long> (nums.size() + 1));
        low = lower;
        up = upper;


        long long sum = 0;
        int i = 0;
        sums[i] = 0;
        for (auto &x : nums) {
            ++i;

            sum += x;
            sums[i] = sum;
        }
        //cout << sums << endl;
        return merge_counting(0, nums.size());
    }
private:
    vector<long long> sums;
    int low;
    int up;

    int merge_counting(int s, int e) {
        if (s >= e)
            return 0;

        auto mid = (s + e) / 2;

        /* count ranges not accross mid */
        auto count = merge_counting(s, mid);
        count += merge_counting(mid+1, e);

        /* count ranges cross mid */
        auto rg_s = mid + 1; // rg_s to rg_e is valid ranges
        auto rg_e = mid + 1;
        auto mg_s = mid + 1;
        vector<long long> tmp;
        for (auto i=s; i <= mid; ++i) {
            while (rg_s <= e && sums[rg_s] - sums[i] < low) // find start
                ++rg_s;
            while (rg_e <= e && sums[rg_e] - sums[i] <= up)
                ++rg_e;
            count += rg_e - rg_s;

            /* merge left and right */
            while (mg_s <= e && sums[i] > sums[mg_s]) {
                tmp.emplace_back(sums[mg_s]);
                ++mg_s;
            }
            tmp.emplace_back(sums[i]);
        }

        copy(tmp.begin(), tmp.end(), sums.begin()+s);
        //cout << sums << endl;
        return count;
    }
};

int main() {
    vector<int> input = {-2,5,-1};
    cout << Solution{}.countRangeSum(input, -2, 2) << endl;
}
