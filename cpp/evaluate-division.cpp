/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/

/* euquivalent to find path in a graph */
/* O(V + q*V^2), O(V^2)*/
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        lookup.clear();
        for (int i=0; i<equations.size(); ++i) {
            lookup[equations[i].first][equations[i].second] = values[i];
            if (values[i])
                lookup[equations[i].second][equations[i].first] = 1.0/values[i];
        }

        vector<double> res;
        for (auto &que : queries) {
            unordered_map<string, bool> visited;

            if (check_and_update(que.first, que.second, visited)) {
                res.emplace_back(lookup[que.first][que.second]);
            } else {
                res.emplace_back(-1.0);
            }
        }

        return res;
    }
private:
    unordered_map<string, unordered_map<string, double>> lookup;
    bool check_and_update(const string &num, const string &denom, unordered_map<string, bool> &visited) {
        if (lookup[num].find(denom) != lookup[num].end()) {
            return true;
        }

        visited[num] = true;
        for (auto &down : lookup[num]) {
            if (!visited[down.first]) {
                visited[down.first] = true;
                if (check_and_update(down.first, denom, visited)) {
                    lookup[num][denom] = down.second * lookup[down.first][denom];
                    return true;
                }
            }
        }

        return false;
    }
};
