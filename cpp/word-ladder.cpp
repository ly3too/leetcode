/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
*/

/* breadth first search, generate nextnode according to each ch */
/* O(n), O(n) */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<unordered_set<char>> ch_lookup(beginWord.size());
        unordered_map<string, bool> visited;

        /* Initialize lookups */
        for (auto &word : wordList) {
            visited[word] = false;
            for (int i=0; i<beginWord.size(); ++i) {
                ch_lookup[i].insert(word[i]);
            }
        }

        queue<string> que;
        que.emplace(beginWord);
        int level = 1;

        while(!que.empty()) {
            auto size = que.size();
            //cout << endl << level << "th level:" << endl;
            //lookup every level
            while (size--){
                auto cur_str = que.front();
                que.pop();
                //cout << '-' << cur_str << endl;

                if (cur_str == endWord)
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

        return 0;
    }
};
