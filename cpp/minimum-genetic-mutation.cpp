/*
A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

Note:

Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.
Example 1:
start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1
Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2
Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3
*/

/* same as word ladder */
/* O(n*L), O(n) */
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<unordered_set<char>> ch_lookup(start.size());
        unordered_map<string, bool> visited;

        /* Initialize lookups */
        for (auto &word : bank) {
            visited[word] = false;
            for (int i=0; i<start.size(); ++i) {
                ch_lookup[i].insert(word[i]);
            }
        }

        queue<string> que;
        que.emplace(start);
        int level = 0;

        while(!que.empty()) {
            auto size = que.size();
            //cout << endl << level << "th level:" << endl;
            //lookup every level
            while (size--){
                auto cur_str = que.front();
                que.pop();
                //cout << '-' << cur_str << endl;

                if (cur_str == end)
                    return level;

                // generate next level
                for (auto i=0; i < cur_str.size(); ++i) {

                    auto new_str = cur_str;
                    for (auto ch : ch_lookup[i]) {
                        new_str[i] = ch;
                        //cout << i << "th ch=" << ch << " new_str= "<< new_str << endl;
                        if (visited.find(new_str) != visited.end() && !visited[new_str]) {
                            visited[new_str] = true;
                            que.emplace(new_str);
                            //cout << "valid_str = " << new_str << endl;
                        }
                    }
                }
            }

            ++level;
        }

        return -1;
    }
};
