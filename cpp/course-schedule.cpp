/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

/* BFS, do topological sort, if we find a sort then return true, else return false. use in_nodes[] indicates
nodes connect to the input of a node, using out_nodes[] indicate out_nodes,
zero_in_nodes[] indicate nodes with zero in-degree */

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> in_nodes;
        unordered_map<int, unordered_set<int>> out_nodes;
        queue<int> zero_in_nodes;

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
            return true;
        }

        return false;
    }
};
