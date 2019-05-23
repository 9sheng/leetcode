#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;

        if (s.size() < 10) {
            return result;
        }

        for (size_t i = 0; i < s.size() - 9; ++i) {
            ++m_occurNum[DnaKey(s.data() + i)];
        }

        char buffer[12];
        buffer[10] = '\0';

        for (auto iter = m_occurNum.begin(); iter != m_occurNum.end();
             ++iter)
        {
            if ((*iter).second > 1)
            {
                memcpy(buffer, (*iter).first.data(), 10);
                result.push_back(string(buffer));
            }
        }

        return result;
    }

    class DnaKey {
    public:
        DnaKey(const char* data)
                : m_data(data) {
        }

        bool operator< (const DnaKey& rhs) const {
            return memcmp(m_data, rhs.m_data, 10) < 0;
        }

        const char* data() const {
            return m_data;
        }

    private:
        const char* m_data;
    };

    std::map<DnaKey, int> m_occurNum;
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
