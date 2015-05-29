#include "testharness.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;

        string buffer(n * 2, '0');

        doGenerateParenthesis(n, 0, 0, buffer, result);
        return result;
    }

private:
    void doGenerateParenthesis(int n, int p, int q, string& buffer, vector<string>& result) {
        assert(p >= q);

        if (p == n) {
            for (int i = p + q; i < 2 * n; i++)
                buffer[i] = ')';
            result.push_back(buffer);
            return;
        }

        int next = p + q;
        if (p > q) {
            buffer[next] = ')';
            doGenerateParenthesis(n, p, q+1, buffer, result);
        }

        buffer[next] = '(';
        doGenerateParenthesis(n, p+1, q, buffer, result);
    }
};

TEST(Solution, test) {
    auto result = generateParenthesis(3);
    for (auto iter = result.begin(); iter != result.end(); ++iter)
        std::cout << *iter << std::endl;
    ASSERT_EQ(2, 1+1);
}
