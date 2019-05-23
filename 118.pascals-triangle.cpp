#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;
        if (numRows < 1) return result;

        result.resize(numRows, vector<int>({1}));

        for (int i = 1; i < numRows; i++) {
            result[i].resize(i+1);
            for (int j = 1; j < i; j++) {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
            result[i][i] = 1;
        }

        return result;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
    auto result = generate(15);
    for (auto iter1 = result.begin(); iter1 != result.end(); ++iter1) {
        for (auto iter2 = (*iter1).begin(); iter2 != (*iter1).end(); ++iter2) {
            std::cout << *iter2 << " ";
        }
        std::cout << endl;
    }
}
