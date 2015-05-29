#include "testharness.h"
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <functional>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // O(N*log(k))
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct ListNodePtrCmp : public std::less<ListNode*> {
            bool operator()(const ListNode* ptr1, const ListNode* ptr2) const {
                return ptr1->val > ptr2->val;
            }
        };

        priority_queue<ListNode*, std::vector<ListNode*>, ListNodePtrCmp> ptr_queue;
        for (auto iter = lists.begin(); iter != lists.end(); ++iter) {
            if (*iter != NULL) ptr_queue.push(*iter);
        }

        ListNode head(0);
        ListNode* current = &head;
        while (!ptr_queue.empty()) {
            auto current_min = ptr_queue.top();
            ptr_queue.pop();
            current->next = current_min;

            int queue_min = ptr_queue.top()->val;
            auto tmp = current_min->next;
            while (tmp != NULL && tmp->val < queue_min) {
                current_min = tmp;
                tmp = current_min->next;
            }

            current = current_min;
            if (current_min->next != NULL) ptr_queue.push(current_min->next);
        }

        return head.next;
    }
};



TEST(Solution, test) {
    ListNode a1(1);
    ListNode b1(2);
    ListNode c1(3);
    ListNode d1(4);
    ListNode e1(5);
    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;
    d1.next = &e1;

    ListNode a2(0);
    ListNode b2(2);
    ListNode c2(2);
    ListNode d2(3);
    ListNode e2(5);
    a2.next = &b2;
    b2.next = &c2;
    c2.next = &d2;
    d2.next = &e2;

    ListNode a3(0);
    ListNode b3(1);
    ListNode c3(1);
    ListNode d3(1);
    ListNode e3(8);
    a3.next = &b3;
    b3.next = &c3;
    c3.next = &d3;
    d3.next = &e3;

    vector<ListNode*> lists({&a1, &a2, &a3});
    ListNode* current = mergeKLists(lists);

    int i = 0;
    while (current->next != NULL) {
        i++;
        auto next = current->next;
        ASSERT_LE(current->val, next->val);
        current = next;
    }
    ASSERT_LE(14, i);
}
