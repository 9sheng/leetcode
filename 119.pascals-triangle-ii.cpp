#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;

        vector<int> result(rowIndex, 1);
        if (rowIndex < 3) return result;

        vector<int> tmp(rowIndex, 1);
        for (int i = 2; i < rowIndex; i++) {
            for (int j = 1; j < i; j++) {
                tmp[j] = result[j-1] + result[j];
            }
            swap(result, tmp);
        }

        return result;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
    auto result = getRow(3);
    for (auto iter1 = result.begin(); iter1 != result.end(); ++iter1) {
        std::cout << *iter1 << " ";
    }
    std::cout << "\n";
}
