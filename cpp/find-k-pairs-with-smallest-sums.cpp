/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
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
#include <queue>
#include <typeinfo>
#include "print_container.hpp"

using namespace std;

/* if(nums[i], nums[j]) is the min one, then next min be (nums[i+1], nums[j])
or (nums[i], nums[j+1]) or previous elements in the que */
/* using min queue, O(k*log(min(m,n,k))), O(min(m,n,k))*/
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;

        using P = pair<int, pair<int, int>>;
        priority_queue<P, vector<P>, greater<P>> que;

        const auto n1 = nums1.size();
        const auto n2 = nums2.size();

        if (n1==0 || n2 == 0)
            return res;

        que.emplace(nums1[0] + nums2[0], make_pair(0, 0));
        while (!que.empty() && res.size()<k) {
            int i, j;
            tie(i, j) = que.top().second;
            que.pop();
            res.emplace_back(nums1[i], nums2[j]);

            if (j+1 < n2) {
                que.emplace(nums1[i] + nums2[j+1], make_pair(i, j+1));
            }

            /* to avoid repetation e.g. 1,0 0,1 only get one 1,1 */
            if (j==0 && i+1 < n1) {
                que.emplace(nums1[i+1] + nums2[j], make_pair(i+1, j));
            }

        }

        return res;
    }
};
