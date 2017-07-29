/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <ctime>
#include <ctype.h>
#include <sstream>
#include <map>
#include <cmath>
#include <deque>
#include <unordered_map>
#include <typeinfo>
#include "print_container.hpp"

using namespace std;

/* using a dequeue to store the useful index where the number is the bigest number
biger than the left elements in the window, and laler the bigest number's index that is
smaller than the previous biggest number. if the index at the front of the queue is out of window,
remove it. so elements corespunding to the index queue is in descending order,
the front is the current biggest number. O(n), O(k)  */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k <= 1)
            return nums;

        vector<int> res;
        deque<int> qi;
        int i;
        for (i=0; i<k; ++i) {
            while (!qi.empty() && nums[i] >= nums[qi.back()]) {
                qi.pop_back();
            }
            qi.emplace_back(i);
        }
        res.emplace_back(nums[qi.front()]);

        for (; i<nums.size(); ++i) {
            if (qi.front() <= i-k)
                qi.pop_front();

            while (!qi.empty() && nums[i] >= nums[qi.back()]) {
                qi.pop_back();
            }
            qi.emplace_back(i);

            res.emplace_back(nums[qi.front()]);
        }

        return res;
    }
};
