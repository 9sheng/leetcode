#include "testharness.h"
#include <string>
#include <string.h>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* head = new ListNode(0);
        ListNode* current = head;
        ListNode* prior = NULL;
        int carrierBit = 0;

        while (l1 != NULL && l2 != NULL) {
            int tmp = l1->val + l2->val + carrierBit;

            if (tmp > 9) {
                current->val = tmp - 10;
                carrierBit = 1;
            } else {
                current->val = tmp;
                carrierBit = 0;
            }

            l1 = l1->next;
            l2 = l2->next;

            current->next = new ListNode(0);
            prior = current;
            current = current->next;
        }

        ListNode* l = l1 == NULL ? l2 : l1;
        while (l != NULL) {
            int tmp = l->val + carrierBit;
            if (tmp > 9) {
                current->val = tmp - 10;
                carrierBit = 1;
            } else {
                current->val = tmp;
                carrierBit = 0;
            }


            current->next = new ListNode(0);
            prior = current;
            current = current->next;
            l = l->next;
        }

        if (carrierBit == 0) {
            delete current;
            if (prior != NULL) {
                prior->next = NULL;
            }
        } else {
            current->val = carrierBit;
        }

        return head;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
