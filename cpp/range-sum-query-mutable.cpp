/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
*/

#include "header.hpp"

/* Binary index tree, time: O(n), O(logn), O(logn); space: O(n) */
class NumArray {
public:
    NumArray(vector<int>&& nums) : nums_{move(nums)} {
        N = nums_.size();
        bit_ = vector<int>(N+1, 0);

        for (int i=1; i<=N; ++i) {
            bit_[i] = bit_[i-1]+nums_[i-1];
        }
        for (int i=N; i>0; --i) {
            bit_[i] -= bit_[i-(i&-i)];
        }
    }

    void update(int i, int val) {
        if (i<N) {
            update_add(i, val - nums_[i]);
            nums_[i] = val;
        }
    }

    int sumRange(int i, int j) {
        return sum(j) - sum(i-1);
    }

private:
    vector<int> bit_;
    vector<int> nums_;
    size_t N;

    void update_add(int i, int val) {
        ++i;
        while (i<=N) {
            bit_[i] += val;
            i += (i&-i);
        }
    }

    int sum(int i) {
        ++i;
        int sum = 0;
        while (i>0) {
            sum += bit_[i];
            i -= (i&-i);
        }

        return sum;
    }
};

/* segment tree; time: O(n), O(logn), O(logn); space: O(n) */
class NumArray2 {
public:
    NumArray2(vector<int>&& nums) : nums_{move(nums)} {
        N = nums_.size();
        N_st = 2 * (1 << (static_cast<int> (ceil(log2(N))))) - 1;
        st_ = vector<int>(N_st);
        // cout << N_st << " " << log2(N) << endl;
        if (N)
            construct_st(0, N-1, 0);
    }

    void update(int i, int val) {
        if (i>=0 && i < N) {
            update_st(0, N-1, i, val-nums_[i], 0);
            nums_[i] = val;
        }
    }

    int sumRange(int i, int j) {
        if (i<0 || j >= N || j < i) {
            return 0;
        }
        return sum_st(0, N-1, i, j, 0);
    }

private:
    vector<int> st_;
    vector<int> nums_;
    size_t N;
    size_t N_st;

    int construct_st(int nb, int ne, int node) {
        if (nb == ne) {
            st_[node] = nums_[nb];
            return st_[node];
        }

        int mid = (ne+nb)/2;
        st_[node] = construct_st(nb, mid, 2*node+1) + construct_st(mid+1, ne, 2*node+2);
        return st_[node];
    }

    void update_st(int nb, int ne, int i, int diff, int node) {
        if (i<=ne && i>=nb) {
            st_[node] += diff;
            if (nb < ne) {
                int mid = (ne+nb)/2;
                update_st(nb, mid, i, diff, 2*node+1);
                update_st(mid+1, ne, i, diff, 2*node+2);
            }
        }
    }

    int sum_st(int nb, int ne, int i, int j, int node) {
        /* [nb,ne] in [i, j] */
        if (i<=nb && j>=ne) {
            return st_[node];
        }

        /* no overlape */
        if (i>ne || j<nb) {
            return 0;
        }

        /* some overlape */
        int mid = (ne+nb)/2;
        return sum_st(nb, mid, i, j, 2*node+1) + sum_st(mid+1, ne, i, j, 2*node+2);
    }

};

int main() {
    NumArray2 nr{vector<int>{1,3,5}};
    cout << nr.sumRange(0,2) << endl;
}
