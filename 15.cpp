#include "testharness.h"
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int size = num.size();
        vector<vector<int>> result;
        if (size <= 2) return result;

        std::map<int, int> nmap;
        for (auto iter = num.begin(); iter != num.end(); ++iter)
            nmap[*iter]++;

        for (auto iter = nmap.begin(); iter != nmap.end(); ++iter) {
            if (iter->first == 0) {
                if (iter->second > 2) result.push_back({0, 0, 0});
                continue;
            }

            if (iter->second > 1) {
                int t = - iter->first - iter->first;
                if (nmap.find(t) != nmap.end()) {
                    if (t > iter->first)
                        result.push_back({iter->first, iter->first, t});
                    else
                        result.push_back({t, iter->first, iter->first});
                }
            }

            auto iter2 = iter;
            for (++iter2; iter2 != nmap.end(); ++iter2) {
                int t = iter->first + iter2->first;
                if (t > 0) break;
                if (iter2->first + t >= 0) continue;

                if (nmap.find(-t) != nmap.end())
                    result.push_back({iter->first, iter2->first, -t});
            }
        }

        return result;
    }
};

TEST(Solution, test) {
    {
        vector<int> num({-1, 0, 1, 2, -1, -4});
        auto result = threeSum(num);
        for (auto iter = result.begin(); iter != result.end(); ++iter) {
            std::cout << (*iter)[0] << " " << (*iter)[1] << " " << (*iter)[2] << std::endl;
            ASSERT_EQ(0, (*iter)[0] + (*iter)[1]+ (*iter)[2]);
            ASSERT_LE((*iter)[0], (*iter)[1]);
            ASSERT_LE((*iter)[1], (*iter)[2]);
        }
    }

    {
        vector<int> num({1, 1, -2});
        auto result = threeSum(num);
        for (auto iter = result.begin(); iter != result.end(); ++iter) {
            std::cout << (*iter)[0] << " " << (*iter)[1] << " " << (*iter)[2] << std::endl;
            ASSERT_EQ(0, (*iter)[0] + (*iter)[1]+ (*iter)[2]);
            ASSERT_LE((*iter)[0], (*iter)[1]);
            ASSERT_LE((*iter)[1], (*iter)[2]);
        }
    }

    {
        vector<int> num({1, 0, -1});
        auto result = threeSum(num);
        for (auto iter = result.begin(); iter != result.end(); ++iter) {
            std::cout << (*iter)[0] << " " << (*iter)[1] << " " << (*iter)[2] << std::endl;
            ASSERT_EQ(0, (*iter)[0] + (*iter)[1]+ (*iter)[2]);
            ASSERT_LE((*iter)[0], (*iter)[1]);
            ASSERT_LE((*iter)[1], (*iter)[2]);
        }
    }

    ASSERT_EQ(2, 1+1);
}
