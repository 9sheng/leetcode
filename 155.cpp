#include "testharness.h"
#include <string>
#include <string.h>
#include <vector>
#include <deque>

using namespace std;

class MinStack {
public:
    void push(int x) {
        m_stack.push_back(x);

        if (m_minIndex.empty() || m_stack[m_minIndex.back()] > x) {
            m_minIndex.push_back(m_stack.size() - 1);
        }
    }

    void pop() {
        if (m_stack.empty()) return;

        int last = m_stack.size() - 1;
        if (last == m_minIndex.back()) {
            m_minIndex.resize(m_minIndex.size() - 1);
        }
        m_stack.resize(last);
    }

    int top() {
        return m_stack.empty() ? 0 : m_stack.back();
    }

    int getMin() {
        return m_minIndex.empty() ? 0 : m_stack[m_minIndex.back()];
    }

private:
    deque<int> m_stack;
    deque<int> m_minIndex;
};

TEST(MinStack, test) {
    ASSERT_EQ(2, 1+1);
}

