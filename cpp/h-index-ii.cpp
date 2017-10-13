/*
What if the citations array is sorted in ascending order? Could you optimize your algorithm?
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        auto s = 0;
        auto n = static_cast<int>(citations.size());
        auto e = n - 1;

        while (s <= e) {
            auto mid = (s + e) / 2;
            if (n - mid <= citations[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return n - s;
    }
};
