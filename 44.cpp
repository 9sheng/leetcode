#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
 bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;
        while (*s){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}

            // * found in pattern, track index of *, only advancing pattern pointer
            if (*p=='*'){star=p++; ss=s;continue;}

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (star){ p = star+1; s=++ss;continue;}

           //current pattern pointer is not star, last patter pointer was not *
           //characters do not match
            return false;
        }

       //check for remaining characters in pattern
        while (*p=='*'){p++;}

        return !*p;
    }


private:
    bool doMatch(const char *s, const char *p, int m, int n) {

        if (m_matchTable[m][n] != 0) return m_matchTable[m][n] == 1;

        switch (*p) {
            case '\0':
                return *s == '\0';

            case '?':
                return tryCacheMatch(s+1, p+1, m+1, n+1) == 1;

            case '*':
                while(*p == '*') {
                    ++p;
                    ++n;
                }

                if (*p == '\0') {
                    return true;
                }

                 while (true) {
                    if (*p != '?') {
                        while (*s != *p) {
                            if (*s == '\0') {
                                return false;
                            }
                            ++s;
                        }
                    }

                    {
                        int ret = tryCacheMatch(++s, p+1, ++m, n+1);
                        if (ret == 1) return true;
                    }

                    if (*s == '\0') {
                        return false;
                    }
                }

            default:
                return *p == *s ? tryCacheMatch(s+1, p+1, m+1, n+1) == 1 : false;
        }
    }

    int tryCacheMatch(const char *s, const char *p, int m, int n) {
        if (m_matchTable[m][n] == 0) {
            m_matchTable[m][n] = doMatch(s, p, m, n) ? 1 : -1;
        }
        return m_matchTable[m][n];
    }

    struct Pattern {
        const char* ptr;
        const int size;
    };

    bool firstMatch(const char *s, const char *p) {
        decodePattern(p);

        for (size_t i = 0; i < m_patterns.size(); ++i) {
            const char* ptr = find(s, m_patterns[i]);
            if (ptr == NULL) return false;
            s = ptr + m_patterns[i].size;
        }

        return true;
    }

    void decodePattern(const char* p) {
        while (*p == '*') {
            p++;
        }

        const char* base = p;

        while (*p != '\0') {
            if (*p == '*') {
                m_patterns.push_back(Pattern({base, p - base}));
                while (*p == '*') {
                    ++p;
                }
                base = p;
            } else {
                ++p;
            }
        }
    }

    const char* find(const char* s, const Pattern& p) {
        int len = strlen(s);
        if (len < p.size) return NULL;

        while (len >= p.size) {
            const char* sp = s;
            const char* ptr = p.ptr;

            for (int i = 0; i < p.size; ++i) {
                if (ptr[i] != '?' && sp[i] != ptr[i]) {
                    ++s;
                    break;
                }
            }

            if (sp == s) return s;
            len--;
        }

        return NULL;
    }

private:
    vector<Pattern> m_patterns;
    map<int, map<int, int>> m_matchTable;
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
