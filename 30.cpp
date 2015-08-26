#include "testharness.h"
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
#include <limits.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        int word_len = words[0].size();
        int words_size = words.size();
        int end = s.size() - word_len * words_size;

        if (words_size == 0 || end < 0) return result;

        std::set<int> flag;
        unordered_map<string, int> word_to_index;

        for (int i = 0; i < words_size; ++i)
            word_to_index[words[i]] = i;

        for (int i = 0; i < end; i++) {
            for (int j = 0; j < words_size; j++)
                flag.insert(j);

            for (int j = 0; j < words_size; j++) {
                auto iter = word_to_index.find(s.substr(i + j * word_len, word_len));
                if (iter != word_to_index.end())
                    flag.erase((*iter).second);
                else
                    break;
            }

            if (flag.empty()) result.push_back(i);
        }

        return result;
    }
};

TEST(Solution, test) {
    std::string s = "barfoothefoobarman";
    vector<string> words({"foo", "bar"});
    vector<int> result = findSubstring(s, words);

    ASSERT_EQ(2, result.size());
    ASSERT_EQ(0, result[0]);
    ASSERT_EQ(9, result[1]);
}

