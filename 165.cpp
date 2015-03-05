#include "testharness.h"
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> ver1;
        vector<string> ver2;

        split(version1, &ver1);
        split(version2, &ver2);

        if (ver1.size() < ver2.size()) {
            ver1.resize(ver2.size(), "0");
        } else if (ver2.size() < ver1.size()) {
            ver2.resize(ver1.size(), "0");
        }

        for (size_t i = 0; i < ver1.size(); ++i) {
            int ret = compareString(ver1[i], ver2[i]);
            if (ret != 0) return ret;
        }

        return 0;
    }

private:
    void split(const string& str, vector<string>* out) {
        std::size_t pos = 0;

        while (true) {
            while (str[pos] == '0') {
                pos++;
            }

            if (pos == str.size()) {
                (*out).push_back("0");
                return;
            } else if (str[pos] == '.') {
                (*out).push_back("0");
                pos++;
            } else {
                size_t nextPos = str.find_first_of(".", pos);
                if (nextPos == string::npos) {
                    (*out).push_back(str.substr(pos));
                    return;
                } else {
                    (*out).push_back(str.substr(pos, nextPos - pos));
                    pos = nextPos + 1;
                }
            }
        }
    }

    int compareString(const string& str1, const string& str2) const {
        size_t size1 = str1.size();
        size_t size2 = str2.size();

        int diff = size1 - size2;
        if (diff != 0)
            return diff > 0 ? 1 : -1;

        diff = strcmp(str1.c_str(), str2.c_str());
        return diff > 0 ? 1 : diff < 0 ? -1 : 0;
    }

};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
