/*
Implement a magic directory with buildDict, and search methods.

For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word,
 the modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
Note:
You may assume that all the inputs are consist of lowercase letters a-z.
For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across
multiple test cases. Please see here for more details.
*/


class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto &str : dict) {
            trie.insert(str);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return find_recur(word, 0, &trie, true);
    }

private:
    struct trie_node {
        bool is_string = false;
        unordered_map<char, trie_node*> leaves;

        bool insert(string &s) {
            auto p = this;

            for (auto ch : s) {
                if (p -> leaves.find(ch) == leaves.end()) {
                    p -> leaves[ch] = new trie_node;
                }
                p = p -> leaves[ch];
            }

            if (p -> is_string) {
                return false;
            } else {
                p -> is_string = true;
                return true;
            }
        }

        ~trie_node() {
            for (auto &leaf : leaves) {
                if (leaf.second)
                    delete leaf.second;
            }
        }
    } trie;

    bool find_recur(string &word, int idx, trie_node* node, bool mistake_allowed) {
        if (!node)
            return false;

        if (idx == word.size()) {
            return  node -> is_string && !mistake_allowed;
        }

        if (node -> leaves.count(word[idx])) {
            if (mistake_allowed) {
                return find_recur(word, idx+1, node -> leaves[word[idx]], true) ||
                    any_of(node -> leaves.begin(), node -> leaves.end(),
                        [&](const pair<char, trie_node*>& p){
                            return p.first != word[idx] && find_recur(word, idx+1, p.second, false);});
            } else {
                return find_recur(word, idx+1, node -> leaves[word[idx]], false);
            }
        }

        if (mistake_allowed) {
            return any_of(node -> leaves.begin(), node -> leaves.end(),
                [&](const pair<char, trie_node*>& p){ return  find_recur(word, idx+1, p.second, false);});
        } else {
            return false;
        }
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
