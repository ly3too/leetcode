/*Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/


/* sort by height in descending order, by number of people infront in ascending order, then insert one by one , O(n^2), O(n)*/
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
            return a.first == b.first ? a.second < b.second : b.first < a.first;};

        sort(people.begin(), people.end(), cmp);

        vector<pair<int, int>> res;
        for (auto &p : people) {
            res.insert(res.begin() + p.second, p);
        }

        return res;
    }
};

/* sort by height in descending order, by number of people infront in ascending order, then insert one by one , O(n^2), O(1)*/
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
            return a.first == b.first ? a.second < b.second : b.first < a.first;};

        sort(people.begin(), people.end(), cmp);

        auto N = people.size();
        for (int i=0; i<N; ++i) {
            auto tmp = people[i];
            for (int j=i; j>tmp.second; --j) {
                people[j] = people[j-1];
            }
            people[tmp.second] = tmp;
        }

        return people;
    }
};
