/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/
#include "header.hpp"

/* BFS search and trace back to get the path */
/* O(n*d), O(n*d) */
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord)
            return {vector<string>{beginWord}};

        trace.clear();
        for (auto &word : wordList) {
            dict[word] = false;
        }
        auto const n = beginWord.size();
        queue<const string*> que;
        que.emplace(&beginWord);

        bool found = false;
        while (!que.empty() && !found) {
            auto size = que.size();
            vector<unordered_map<string, bool>::iterator> visited_dicts;

            while (size--) {
                auto node = que.front();
                que.pop();
                //cout << *node << ": " << endl;

                /* try new word, if new_word == endWord, dont mark dict[new_word] as true to allow multi-trace */
                for (int i=0; i<n; ++i) {
                    auto new_word = *node;
                    for (char ch='a'; ch<='z'; ++ch) {
                        new_word[i] = ch;
                        auto it = dict.find(new_word);
                        if (it != dict.end() && !dict[new_word]) {
                            trace[&(it->first)].insert(node);

                            //cout << new_word << endl;
                            if (new_word == endWord) {
                                found = true;
                                break;
                            }
                            visited_dicts.emplace_back(it);
                            que.emplace(&(it->first));
                        }
                    }

                    if (new_word == endWord) {
                        break;
                    }
                }

                //cout << endl;
            }

            for (auto it : visited_dicts) {
                //cout << "visited " << it -> first << endl;
                it -> second = true;
            }

            //cout << "---------------------------" << endl;
        }

        if (found)
            trace_back(&(dict.find(endWord) -> first));

        //cout << found << endl;
        return res;
    }
private:
    vector<vector<string>> res;
    unordered_map<const string*, unordered_set<const string*>> trace;
    unordered_map<string, bool> dict;
    vector<const string*> rev_res;

    void trace_back (const string* word) {
        if (trace.find(word) == trace.end()) {
            rev_res.emplace_back(word);
            vector<string> tmp_res;
            for (auto it=rev_res.rbegin(); it != rev_res.rend(); ++it) {
                tmp_res.emplace_back(**it);
            }
            res.emplace_back(move(tmp_res));
            rev_res.pop_back();
            return;
        }

        rev_res.emplace_back(word);
        for (auto it : trace[word]) {
            trace_back(it);
        }
        rev_res.pop_back();
    }
};

int main() {
    vector<string> wordList {"ted","tex","red","tax","tad","den","rex","pee"};
    cout << Solution{}.findLadders("red", "tax", wordList);
}
