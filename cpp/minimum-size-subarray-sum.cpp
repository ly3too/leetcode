/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ? s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


/* O(n) solution */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = static_cast<int>(nums.size());
        int min_sub = numeric_limits<int>::max();

        bool found = false;
        int start = 0;
        int sum = 0;
        for (int end = 0; end < size; ++end) {
            sum += nums[end];
            while (sum >= s) {
                min_sub = min(min_sub, end - start + 1);
                sum -= nums[start++];
                found = true;
            }
        }

        return found? min_sub: 0;
    }
};

class Solution2 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = static_cast<int>(nums.size());
        int min_sub = numeric_limits<int>::max();
        bool found = false;

        vector<int> sums{0};
        int sum = 0;
        for (auto x : nums) {
            sum += x;
            sums.push_back(sum);
        }

        for (int i=0; i <= size; ++i) {
            auto x = sums[i];
            if (x < s)
                continue;
            auto beg = bin_search(x-s, sums, 0, i+1);
            if (beg >= 0) {
                cout << i << " " << beg << endl;
                min_sub = min(min_sub, i - beg + 1);
                found = true;
            }
        }

        return found? min_sub: 0;
    }
private:
    int bin_search(int target, vector<int>& sums, int begin, int end) {

        bool found = false;
        while (begin < end) {
            int mid = (begin + end) / 2;
            if (sums[mid] > target) {
                end = mid;
                found = true;
            } else {
                begin = mid + 1;
            }
        }

        return found? begin: -1;
    }
};

/* Solution3: binary search min_size, for each min_size O(n) times, total O(nlogn), O(1) space */

int main () {
    vector<int> input {1,2,3,4,5};
    // vector<int> input {-1, 0, 1};

    Solution2 s;
    auto output = s.minSubArrayLen(10 ,input);

    cout << output << endl;

    return 0;
}
