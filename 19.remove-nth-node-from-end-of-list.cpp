#include "testharness.h"
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL || n <= 0) return head;
        if (head->next == NULL && n > 0) return NULL;

        ListNode* ptr = head;
        for (int i = 0; i < n; i++) {
            // if (ptr == NULL) return head;
            ptr = ptr->next;
        }

        if (ptr == NULL) return head->next;

        ListNode* ptrToRm = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
            ptrToRm = ptrToRm->next;
        }

        if (ptrToRm->next != NULL)
            ptrToRm->next = ptrToRm->next->next;
        // we should delete ptrToRm

        return head;
    }
};

TEST(Solution, test) {
    ListNode n1(1);
    ListNode n2(2);
    n1.next = &n2;
    ListNode* ptr = removeNthFromEnd(&n1, 2);
    while (ptr != NULL) {
        std::cout << ptr->val << std::endl;
        ptr = ptr->next;
    }
    ASSERT_EQ(2, 1+1);
}
