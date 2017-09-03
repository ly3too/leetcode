/*
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi],
where Li and Ri are the x coordinates of the left and right edge of the ith building,
respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX,
and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely
flat surface at height 0.
*/

/* O(nlog(n)), O(n) */
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        enum {LI = 0, RI, HI};
        struct point_info {
            int height;
            bool is_start;
        };

        map<int, vector<point_info>> point_heights; // index and its heights

        for (const auto &building : buildings) {
            point_heights[building[LI]].emplace_back(point_info{building[HI], true});
            point_heights[building[RI]].emplace_back(point_info{building[HI], false});
        }

        map<int, int> heights_cnt; //current heights and its count; only keep heights of current point
        int cur_max = 0;
        vector<pair<int, int>> res;
        for (auto &point : point_heights) {
            auto &index = point.first;
            auto &infos = point.second;

            for (auto &info : infos) {
                if (info.is_start) {
                    ++heights_cnt[info.height];

                } else {
                    --heights_cnt[info.height];

                    // only keep the possible heights of current point
                    if (heights_cnt[info.height] == 0) {
                        heights_cnt.erase(info.height);
                    }
                }
            }

            if (heights_cnt.empty()) {
                cur_max = 0;
                res.emplace_back(make_pair(index, cur_max));

            } else if (cur_max != (heights_cnt.crbegin()->first)) {
                cur_max = heights_cnt.crbegin()->first;
                res.emplace_back(make_pair(index, cur_max));
            }

        }

        return res;
    }
};
