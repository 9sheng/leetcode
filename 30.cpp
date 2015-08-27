#include "testharness.h"
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

        unordered_map<string, int> word_id;
        for (int i = 0; i < ws; i++)
            word_id[words[i]] = i;

        vector<int> matched_status((s.size() + wl - 1) / wl, -1);
        unordered_map<int, int> word_budget;

        for (int k = 0; k < wl; k++) {

            int s_word_num = 0;
            for (int i = k; i < end; i += wl) {
                auto word = s.substr(i, wl);
                auto iter = word_id.find(word);
                matched_status[s_word_num] = iter != word_id.end() ? (*iter).second : -1;
                ++s_word_num;
            }

            word_budget.clear();
            for (int i = 0; i < ws; i++)
                ++word_budget[word_id[words[i]]];

            int start = 0;
            for (int i = 0; i < s_word_num; i++) {
                if (matched_status[i] == -1) {
                    // current word of s is not matching any given word
                    for (int j = start; j < i; j++)
                        ++word_budget[matched_status[j]];
                    start = i + 1;
                    continue;
                } else if (word_budget[matched_status[i]] == 0) {
                    // word matched, but there is no budget
                    while (true) {
                        int old = start++;
                        if (matched_status[old] != matched_status[i])
                            ++word_budget[matched_status[old]];
                        else
                            break;
                    }
                } else {
                    // word matched, and there is budget
                    --word_budget[matched_status[i]];
                    if (i - start + 1 == ws) {
                        result.push_back(k + start * wl);
                        ++word_budget[matched_status[start]];
                        ++start;
                    }
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

        ASSERT_EQ(0, result.size());
    }

    {
        std::string s = "abaababbaba";
        vector<string> words({"ba","ab","ab"});
        vector<int> result = findSubstring(s, words);

        ASSERT_EQ(2, result.size());
        ASSERT_EQ(1, result[0]);
        ASSERT_EQ(3, result[1]);
    }
}

