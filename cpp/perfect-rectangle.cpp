/*
Given N axis-aligned rectangles where N > 0, determine if they all together form
 an exact cover of a rectangular region.
Each rectangle is represented as a bottom-left point and a top-right point.
For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point
 is (1, 1) and top-right point is (2, 2)).
*/
#include "header.hpp"

/* for every point of each corner of each box except boarder points, the only possible
occurance is LB+RB, RT+LT, LT+LB, RT+RB, RB+LB+LT+RT, other situation is false*/
/* O(n), O(n) */
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left = numeric_limits<int>::max();
        int bottom = left;
        int right = numeric_limits<int>::min();
        int top = right;

        enum : int {L=0, B=1, R=2, T=3};

        /* get boarder points */
        for (auto &box : rectangles) {
            left = min(left, box[L]);
            bottom = min(bottom, box[B]);
            right = max(right, box[R]);
            top = max(top, box[T]);
        }

        enum : int {LB=1, RB=2, LT=4, RT=8};
        unordered_map<int, unordered_map<int, int>> points_pos; // the relative position of points

        const vector<pair<int, pair<int, int>>> corner_modes = {
            {L,{B, LB}}, {L,{T, LT}}, {R,{B, RB}}, {R,{T, RT}}
        };

        /* get the modes for all points */
        for (const auto &box : rectangles) {
            for (const auto &corner : corner_modes) {
                auto x = box[corner.first];
                auto y = box[corner.second.first];

                // overlap
                if (points_pos[x][y] & corner.second.second) {
                    return false;
                }
                points_pos[x][y] |= corner.second.second;
            }
        }

        // check all modes;
        const unordered_set<int> valid_modes = {LB|RB, RT|LT, LT|LB, RT|RB, RB|LB|LT|RT};
        for (auto itx=points_pos.cbegin(); itx!=points_pos.cend(); ++itx) {
            for (auto ity=itx->second.cbegin(); ity!=itx->second.cend(); ++ity) {
                if ((itx->first == left || itx->first == right) && (ity->first==bottom || ity->first==top))
                    continue;

                if (valid_modes.find(ity->second) == valid_modes.cend()) {
                    return false;
                }
            }
        }

        return true;
    }
};
