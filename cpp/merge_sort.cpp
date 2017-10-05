#include "header.hpp"

using namespace std;

template <class Valtype, class Comp = less<Valtype>>
void merge_sort(vector<Valtype> &dest, vector<Valtype> &src, int beg, int end, Comp comp = Comp()) {
    if (beg == end) {
        dest[beg] = src[beg];
        return;
    }
    int mid = (beg+end) / 2;
    merge_sort(src, dest, beg, mid, comp);
    merge_sort(src, dest, mid+1, end, comp);

    int i = beg;
    int j = mid+1;
    int k = beg;
    while (i <= mid && j <= end) {
        if (comp(src[i], src[j])) {
            dest[k++] = src[i++];
        } else {
            dest[k++] = src[j++];
        }
    }

    while (i <= mid) {
        dest[k++] = src[i++];
    }

    while (j <= end) {
        dest[k++] = src[j++];
    }
}

template <class Valtype, class Comp = less<Valtype>>
void merge_sort(vector<Valtype> &vet, Comp comp = Comp()) {
    if (vet.size() <= 1)
        return;

    auto cp = vet;
    merge_sort(vet, cp, 0, vet.size()-1, comp);
}

int main() {
    vector<int> input;
    for (int i=0; i < 10000; ++i) {
        input.emplace_back(rand()%10000);
    }

    //cout << input << endl;

    merge_sort(input, less<int>());

    cout << input << endl;
}
