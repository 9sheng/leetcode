#include "testharness.h"
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        int ws = words.size();
        if (ws == 0) return result;

        int wl = words[0].size();
        int end = s.size();
        if (end < 0) return result;

        unordered_map<string, int> uniq_word;
        for (int i = 0; i < ws; i++)
            uniq_word[words[i]] = i;

        queue<int> current_matched;
        unordered_map<int, int> word_left;

        for (int k = 0; k < wl; k++) {
            while (!current_matched.empty())
                current_matched.pop();

            word_left.clear();
            for (int i = 0; i < ws; ++i)
                word_left[uniq_word[words[i]]]++;

            for (int i = k; i < end; i += wl) {
                auto word = s.substr(i, wl);
                auto iter = uniq_word.find(word);

                if (iter != uniq_word.end()) {
                    auto id = (*iter).second;
                    auto count_iter = word_left.find(id);
                    if ((*count_iter).second != 0) {
                        current_matched.push(id);
                        (*count_iter).second--;
                    } else {
                        while (!current_matched.empty()) {
                            int a = current_matched.front();
                            current_matched.pop();
                            if (a == id) break;
                            word_left[a]++;
                        }
                        current_matched.push(id);
                    }
                } else {
                    while (!current_matched.empty())
                        current_matched.pop();
                    for (int j = 0; j < ws; ++j)
                        word_left[uniq_word[words[j]]]++;
                }

                if (current_matched.size() == ws) {
                    int a = current_matched.front();
                    word_left[a]++;
                    current_matched.pop();
                    result.push_back(i - (ws - 1) * wl);
                }
            }
        }

        return result;
    }
};

TEST(Solution, test) {
    {
        std::string s = "barfoothefoobarman";
        vector<string> words({"foo", "bar"});
        vector<int> result = findSubstring(s, words);

        for (int i = 0; i < result.size(); i++)
            std::cout << "res: " << result[i] << std::endl;

        ASSERT_EQ(2, result.size());
        ASSERT_EQ(0, result[0]);
        ASSERT_EQ(9, result[1]);
    }

    {
        std::string s = "foofoothefoofooman";
        vector<string> words({"foo", "foo"});
        vector<int> result = findSubstring(s, words);

        ASSERT_EQ(2, result.size());
        ASSERT_EQ(0, result[0]);
        ASSERT_EQ(9, result[1]);
    }

    {
        std::string s = "barfoofoobarthefoobarman";
        vector<string> words({"bar","foo","the"});
        vector<int> result = findSubstring(s, words);

        for (int i = 0; i < result.size(); i++)
            std::cout << "res: " << result[i] << std::endl;

        ASSERT_EQ(3, result.size());
        ASSERT_EQ(6, result[0]);
        ASSERT_EQ(9, result[1]);
        ASSERT_EQ(12, result[2]);
    }

    {
        std::string s = "abababab";
        vector<string> words({"a", "b", "a"});
        vector<int> result = findSubstring(s, words);

        ASSERT_EQ(3, result.size());
        ASSERT_EQ(0, result[0]);
        ASSERT_EQ(2, result[1]);
        ASSERT_EQ(4, result[2]);
    }

    {
        std::string s = "ababababababababababababababababababababababababababababab";
        vector<string> words({"ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba"});
        vector<int> result = findSubstring(s, words);

        for (int i = 0; i < result.size(); i++)
            std::cout << "res: " << result[i] << std::endl;

        ASSERT_EQ(0, result.size());
    }
}

