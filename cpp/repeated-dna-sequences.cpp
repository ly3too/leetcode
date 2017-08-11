/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/
#include "header.hpp"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> out;
        unordered_map<string, int> smap;
        int N = s.size();

        for (int i=0; i<=N-10; ++i) {
            if (smap[s.substr(i,10)] == 1) {
                out.emplace_back(s.substr(i,10));
            }
            ++smap[s.substr(i, 10)];
        }

        return out;
    }

};
