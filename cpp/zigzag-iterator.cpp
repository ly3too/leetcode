/* construct an iterator to return elements from two vector, a zigzag way
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
#include <queue>
#include <unordered_map>
#include <typeinfo>
#include "print_container.hpp"

using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            q.emplace(v1.size()-1, v1.cbegin());
        }
        if (!v2.empty()) {
            q.emplace(v2.size()-1, v2.cbegin());
        }
    }

    bool has_next() {
        return !q.empty();
    }

    int next() {
        auto size = q.front().first;
        auto it = q.front().second;
        q.pop();
        if (size > 0) {
            q.emplace(size-1, it+1);
        }
        return *it;
    }

private:
    queue<pair<int, vector<int>::const_iterator>> q;
};

int main() {
    vector<int> v1 = {0,2,4,6,8,10};
    vector<int> v2 = {1,3,5,7,9,11,13,15};

    ZigzagIterator it{v1, v2};

    while(it.has_next()) {
        cout << it.next() << " ";
    }

    return 0;
}
