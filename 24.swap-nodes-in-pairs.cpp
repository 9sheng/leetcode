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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode new_head(0);
        ListNode* current = &new_head;

        ListNode* first = head;
        while (first != NULL) {
            ListNode* second = first->next;
            if (second == NULL) {
                current->next = first;
                current = current->next;
                break;
            }

            ListNode* third = second->next;
            current->next = second;
            second->next = first;
            current = first;
            first = third;
        }
        current->next = NULL;
        return new_head.next;
    }
};

TEST(Solution, test) {
    {
        ListNode a1(1);
        ListNode b1(2);
        ListNode c1(3);
        ListNode d1(4);
        ListNode e1(5);
        a1.next = &b1;
        b1.next = &c1;
        c1.next = &d1;
        d1.next = &e1;

        ListNode* current = swapPairs(&a1);
        while (current != NULL) {
            std::cout << current->val << std::endl;
            current = current->next;
        }
    }

    {
        ListNode a1(1);
        ListNode b1(2);
        a1.next = &b1;

        ListNode* current = swapPairs(&a1);
        while (current != NULL) {
            std::cout << current->val << std::endl;
            current = current->next;
        }
    }
}
