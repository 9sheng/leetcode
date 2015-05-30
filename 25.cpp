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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k < 2) return head;

        ListNode dummy(0);
        ListNode* last_tail = &dummy;
        ListNode* left_nodes = head;

        while (left_nodes != NULL) {
            ListNode* new_tail = left_nodes;
            last_tail->next = reverseFirstK(&left_nodes, k);
            last_tail = new_tail;
        }
        return dummy.next;
    }

    ListNode* reverseFirstK(ListNode** left_nodes, int k) {
        assert(k > 1);
        assert(*left_nodes != NULL);

        // first we check whether we can reverse
        int n = 0;
        ListNode* tmp = *left_nodes;
        while (tmp != NULL) {
            if (++n == k) break;
            tmp = tmp->next;
        }
        if (n < k) {
            tmp = *left_nodes;
            *left_nodes = NULL;
            return tmp;
        }

        // do reverse
        ListNode dummy(0);
        ListNode* list_end = &dummy;
        ListNode* current = *left_nodes;

        while (k-- > 0 && current != NULL) {
            ListNode* current_next = current->next;
            current->next = list_end->next;
            list_end->next = current;
            current = current_next;
        }

        *left_nodes = current;
        return dummy.next;
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
        ListNode* head = &a1;
        ListNode* end = NULL;
        ListNode* current = reverseKGroup (&a1, 3);

        while (current != NULL) {
            std::cout << current->val << std::endl;
            current = current->next;
        }
    }
}
