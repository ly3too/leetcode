/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj,
ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers
as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.
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
#include <unordered_map>
#include <typeinfo>
#include "print_container.hpp"

using namespace std;
/* O(n), O(n) */
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() <= 2)
            return false;

        int ak = numeric_limits<int>::min();

        /* find maxmim valid ak, if ai < ak return tru, every number in
            akstk is bigger than current ak */
        stack<int> akstk;
        for (int i = nums.size()-1; i >= 0; --i) {
            if (nums[i] < ak) {
                return true;

                /* found a valid aj, then update ak to the bigest possible num in stak */
            } else if (!akstk.empty() && nums[i] > akstk.top()) {
                do {
                    ak = akstk.top();
                    akstk.pop();
                } while (!akstk.empty() &&  nums[i] > akstk.top());

                akstk.push(nums[i]);
            } else {

                akstk.push(nums[i]);
            }
        }

        return false;
    }
};
