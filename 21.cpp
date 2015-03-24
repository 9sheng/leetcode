#include "testharness.h"
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode head(0);
        ListNode* ptr = &head;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }

        while (l1 != NULL) {
            ptr->next = l1;
            l1 = l1->next;
            ptr = ptr->next;
        }

        while (l2 != NULL) {
            ptr->next = l2;
            l2 = l2->next;
            ptr = ptr->next;
        }

        return head.next;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
