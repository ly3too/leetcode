/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
*/

/* O(nlog(n)), O(1) */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp = [](int n1, int n2) {return to_string(n1)+to_string(n2) > to_string(n2)+to_string(n1);};
        sort(nums.begin(), nums.end(), cmp);

        string res;
        if (nums.size() < 1) {
            return res;
        }

        if (nums[0] == 0) {
            return to_string(0);
        }

        for (auto &x : nums) {
            res += to_string(x);
        }

        return res;
    }
};
