/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Return 0 if the array contains less than 2 elements.
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/
/* devide numbers into n buckets, the gaps of adjecent buckests are the same, max_diff >= (max_val - min_val)/(n-1),
so the max_diff appear between two buckets, O(n), O(n) */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        const int N = nums.size();
        auto max_val = *max_element(nums.cbegin(), nums.cend());
        auto min_val = *min_element(nums.cbegin(), nums.cend());
        auto gap = max(1, (max_val - min_val)/(N - 1));
        auto buckets = vector<pair<int, int>>((max_val - min_val)/gap + 1,
                        make_pair(numeric_limits<int>::max(), numeric_limits<int>::min())); // first is min number in the bucket, second is max;

        for (auto &n : nums) {
            auto i = (n - min_val)/gap;

            buckets[i].first = min(buckets[i].first, n);
            buckets[i].second = max(buckets[i].second, n);
        }

        auto prev_max = min_val;
        auto res = 0;
        for (auto &bucket : buckets) {
            if (bucket.first != numeric_limits<int>::max()) {
                res = max(res, bucket.first-prev_max);
                prev_max = bucket.second;
            }
        }

        return res;
    }
};
