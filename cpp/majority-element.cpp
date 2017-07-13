/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/


#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

/* moore's voting method, O(n), O(1) */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        auto cand = nums[0];
        int cnt = 0;
        for (auto x : nums) {
            if (cand == x)
                ++ cnt;
            else {
                -- cnt;
            }

            if (cnt <= 0) {
                cnt = 1;
                cand = x;
            }
        }

        // check needed
        return cand;
    }
};

/* Hasing map O(n), O(n) */
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        auto n = nums.size();
        unordered_map<int, int> lookup{};

        for (auto x : nums) {
            if (lookup.count(x))
                ++lookup[x];
            else
                lookup[x] = 1;

            if (lookup[x] > n/2)
                return x;
        }

        exit(EXIT_FAILURE);
    }
};

int main () {
    vector<int> input {1,2,3,4,1,1,1,1,1,1};
    // vector<int> input {-1, 0, 1};

    Solution2 s;
    auto output = s.majorityElement(input);

    cout << output << endl;

    return 0;
}
