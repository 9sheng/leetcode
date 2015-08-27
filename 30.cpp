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

        unordered_map<string, int> uniq_word;
        for (int i = 0; i < ws; i++)
            uniq_word[words[i]] = i;

        vector<int> current_matched(s.size() / wl + 1, -1);
        unordered_map<int, int> word_left;

        for (int k = 0; k < wl; k++) {

            int cm = 0;
            for (int i = k; i < end; i += wl) {
                auto word = s.substr(i, wl);
                auto iter = uniq_word.find(word);
                if (iter != uniq_word.end())
                    current_matched[cm] = (*iter).second;
                else
                    current_matched[cm] = -1;
                cm++;
            }

            word_left.clear();
            for (int i = 0; i < ws; i++)
                ++word_left[uniq_word[words[i]]];

            int start = 0;
            for (int i = 0; i < cm; i++) {
                if (current_matched[i] == -1) {
                    for (int j = start; j < i; j++)
                        ++word_left[current_matched[j]];
                    start = i + 1;
                    continue;
                } else {
                    auto& count = word_left[current_matched[i]];
                    if (count != 0) {
                        --count;
                    } else {
                        while (true) {
                            int old = start++;
                            if (current_matched[old] == current_matched[i])
                                break;
                            else
                                ++word_left[current_matched[old]];
                        }
                    }
                }

                if (i - start + 1 == ws) {
                    result.push_back(k + start * wl);
                    ++word_left[current_matched[start]];
                    ++start;
                }
            }
        }

        return result;
    }
};

#define handle_error(msg)                                       \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

TEST(Solution, test) {
    {
        char *addr;
        int fd;
        struct stat sb;
        off_t offset, pa_offset;
        size_t length;
        ssize_t s;

        fd = open("../data.txt", O_RDONLY);
        if (fd == -1)
            handle_error("open");

        if (fstat(fd, &sb) == -1)           /* To obtain file size */
            handle_error("fstat");

        offset = 0;
        length = sb.st_size - offset;

        addr = (char*)mmap(NULL, length, PROT_READ,
                           MAP_PRIVATE, fd, 0);

        if (addr == MAP_FAILED)
            handle_error("mmap");

        std::string ss;
        vector<string> words;
        char *ptr = addr;
        char *start = NULL;
        while (true) {
            if (isalpha(*addr)) {
                if (start == NULL) start = addr;
            } else {
                if (start != NULL) {
                    if (addr - start != 0) {
                        ss = string(start, addr - start);
                        break;
                    }
                    start = NULL;
                }
            }
            addr++;
        }

        start = NULL;
        while (true) {
            if (isalpha(*addr)) {
                if (start == NULL) start = addr;
            } else {
                if (start != NULL) {
                    if (addr - start != 0)
                        words.push_back(string(start, addr - start));
                    start = NULL;
                }
            }
            if (*addr == ']') break;
            addr++;
        }

        std::cout << "ss.len = " << ss.size() << std::endl;
        std::cout << "words.size = " << words.size() << std::endl;
        vector<int> result = findSubstring(ss, words);

        for (int i = 0; i < result.size(); i++)
            std::cout << "res: " << result[i] << std::endl;

           exit(0);
    }

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

