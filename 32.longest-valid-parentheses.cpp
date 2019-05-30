/**
 * 32. Longest Valid Parentheses
 *
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 * Example 2:
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 */

#include "testharness.h"

class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> open_pos;
    vector<int> far_open_pos(s.size(), -1);

    int max = 0;
    for (size_t i = 0; i < s.size(); i++) {
      if  (s[i] == '(') {
        open_pos.push(i);
      } else if  (s[i] == ')' && !open_pos.empty()) {
        int top = open_pos.top();
        open_pos.pop();
        if (top > 1 && far_open_pos[top-1] != -1) {
          far_open_pos[i] = far_open_pos[top-1];
        } else {
          far_open_pos[i] = top;
        }

        int len = i - far_open_pos[i] + 1;
        if (max < len) {
          max = len;
        }
      }
    }

    return max;
  }
};

TEST(Solution, test) {
  std::string str = "(()";
  ASSERT_EQ(2, longestValidParentheses(str));
}

TEST(Solution, test2) {
  std::string str = ")()())";
  ASSERT_EQ(4, longestValidParentheses(str));
}

TEST(Solution, test3) {
  std::string str = "()(())";
  ASSERT_EQ(6, longestValidParentheses(str));
}

TEST(Solution, test4) {
  std::string str = "(";
  ASSERT_EQ(0, longestValidParentheses(str));
}
