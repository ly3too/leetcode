/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto m = nums1.size();
        auto n = nums2.size();
        if (m+n == 0)
            return 0;
        if ((m+n) % 2 != 0) {
            return find_kth_num(nums1, nums2, (m+n)/2);
        } else {
            return (find_kth_num(nums1, nums2, (m+n)/2) + find_kth_num(nums1, nums2, (m+n)/2-1))/2.0;
        }
    }

private:
    int find_kth_num(vector<int>& nums1, vector<int>& nums2, int k) {
        auto m = nums1.size();
        auto n = nums2.size();
        if (n > m || n == m && nums1[0]>nums2[0])
            return find_kth_num(nums2, nums1, k);

        auto start = 0;
        auto end = static_cast<int>(m) - 1;

        while (start < end) {
            auto mid = (start + end + 1) / 2;

            if ((k-mid >= 0 && k-mid < n && nums2[k-mid] < nums1[mid]) || mid > k || k-mid >= n) { // nums1[mid] is bigger than kth number
                end = mid-1;
            } else {
                start = mid;
            }
        }

        cout << k << " " << start << " " << end << endl;

        if (k-end > 0 && k-end <= n)
            return max(nums2[k-end-1], nums1[end]);
        else
            return nums1[end];
    }
};

// Time:  O(log(min(m, n)))
// Space: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1);
        } else {
            return (findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2) +
                    findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1)) / 2.0;
        }
    }

    int findKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B,
                                 int k) {
        const int m = A.size();
        const int n = B.size();

        // Make sure m is the smaller one.
        if (m > n) {
            return findKthInTwoSortedArrays(B, A, k);
        }

        int left = 0;
        int right = m;
        // Find a partition of A and B
        // where min left s.t. A[left] >= B[k - 1 - left]. Thus left is the (k + 1)-th element.
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (0 <= k - 1 - mid && k - 1 - mid < n && A[mid] >= B[k - 1 - mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int Ai_minus_1 = left - 1 >= 0 ? A[left - 1] : numeric_limits<int>::min();
        int Bj = k - 1 - left >= 0 ? B[k - 1 - left] : numeric_limits<int>::min();

        // kth element would be A[left - 1] or B[k - 1 - left].
        return max(Ai_minus_1, Bj);
    }
};
