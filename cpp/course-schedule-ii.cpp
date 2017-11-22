/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> in_nodes;
        unordered_map<int, unordered_set<int>> out_nodes;
        queue<int> zero_in_nodes;
        vector<int> res;

        for (auto &edg : prerequisites) {
            in_nodes[edg.first].insert(edg.second);
            out_nodes[edg.second].insert(edg.first);
        }

        for (int i=0; i<numCourses; ++i) {
            if (in_nodes.find(i) == in_nodes.end()) {
                zero_in_nodes.emplace(i);
            }
        }

        while (!zero_in_nodes.empty()) {
            auto cur_node = zero_in_nodes.front();
            zero_in_nodes.pop();
            res.emplace_back(cur_node);

            if (out_nodes.find(cur_node) != out_nodes.end()) {

                /* delete cur_node from all out_nodes[cur_node]'s in_nodes', if in_nodes[somenode] is empty, add to zero_in_nodes*/
                for (auto node : out_nodes[cur_node]) {
                    in_nodes[node].erase(cur_node);
                    if (in_nodes[node].empty()){
                        zero_in_nodes.emplace(node);
                        in_nodes.erase(node);
                    }
                }
            }
        }

        if (in_nodes.empty()) {
            return res;
        }

        return vector<int>{};
    }
};
