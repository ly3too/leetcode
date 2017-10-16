/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array.
The result should also be sorted in ascending order. If there is a tie, the smaller elements
are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto i = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), x));
        auto j = i;

        while (k-- > 0) {
            if (j >= arr.size() || (i > 0 && abs(arr[i-1]-x) < abs(arr[j]-x))) {
                --i;
            } else {
                ++j;
            }
        }

        return {arr.begin()+i, arr.begin()+j};
    }
};
