/*
Suppose we abstract our file system by a string in the following manner:
The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
dir
    subdir1
    subdir2
        file.ext

Given a string representing the file system in the above format,
return the length of the longest absolute path to file in the abstracted file system.
If there is no file in the system, return 0.
*/

#include "header.hpp"

class Solution {
public:
    int lengthLongestPath(string& input) {
        int max_len = 0;
        stack<pair<int, int>> paths; //first = depth, second = length

        // cout << input << endl;

        istringstream iss{input};
        string line;
        while (getline(iss, line)) {
            istringstream iwords{line};

            // cout << line << endl;

            int depth = 0;
            while (iwords.peek() == '\t') {
                ++depth;
                iwords.get();
            }

            string word;
            getline(iwords, word);
            if (!word.empty()) {
                if (paths.empty()) {
                    paths.push(make_pair(depth, word.size()));

                } else if (paths.top().first < depth) {
                    paths.push(make_pair(depth, paths.top().second + word.size() + 1));

                } else {
                    while(!paths.empty() && paths.top().first >= depth) {
                        paths.pop();
                    }

                    if (!paths.empty())
                        paths.push(make_pair(depth, paths.top().second + word.size() + 1));
                    else
                        paths.push(make_pair(depth, word.size()));
                }

                for (auto &c : word) {
                    if  (c == '.') {
                        max_len = max(max_len, paths.top().second);
                        break;
                    }
                }

                // cout << depth << " : " << word << " max = " << max_len << endl;
            }

        }

        return max_len;
    }
};

int main() {
    string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    // input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    // input = "aaaaaaaaaaaaaaaaaaaaa\n\tsth.png\na\n\taa\n\t\taaa\n\t\t\tfile.txt";
    input = "file name with  space.txt";

    cout << Solution{}.lengthLongestPath(input) << endl;

    return 0;
}
