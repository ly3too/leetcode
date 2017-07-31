/*
Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <ctime>
#include <ctype.h>
#include <sstream>
#include <map>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <typeinfo>
#include "print_container.hpp"

using namespace std;

/* use a min and max queue to store high part and lower part, insert cost O(logn), findMedian O(1) */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() : size_(0) {

    }

    void addNum(int num) {
        ++size_;
        if (size_%2 == 0) {
            h_half.push(num);

        } else {
            l_half.push(num);
        }

        while (!h_half.empty() && h_half.top() < l_half.top()) {
            l_half.push(h_half.top());
            h_half.push(l_half.top());

            l_half.pop();
            h_half.pop();
        }
    }

    double findMedian() {
        if (size_==0)
            return 0;
        return size_%2==0? (h_half.top()+l_half.top())/2.0 : l_half.top();
    }

private:
    size_t size_;
    priority_queue<int, vector<int>, greater<int>> h_half;
    priority_queue<int> l_half;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
