#include "testharness.h"
#include <string>
#include <string.h>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;

        for (size_t i = 0; i < s.length(); i++) {
            switch (s[i]) {
            case '{':
            case '[':
            case '(':
                charStack.push(s[i]);
                break;

            default:
                if (charStack.empty())
                    return false;

                char c = charStack.top();
                if ((c == '{' && s[i] == '}') || (c == '[' && s[i] == ']') || (c == '(' && s[i] == ')')) {
                    charStack.pop();
                } else {
                    return false;
                }
            }
        }

        return charStack.empty();
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
 
