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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        if (lenA == 0) return NULL;

        int lenB = getLength(headB);
        if (lenB == 0) return NULL;

        if (lenB < lenA) {
            for (int i = 0; i < lenA - lenB; i++) {
                headA = headA->next;
            }
        } else if (lenA < lenB) {
            for (int i = 0; i < lenB - lenA; i++) {
                headB = headB->next;
            }
        }

        while (headA != NULL) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }

private:
    int getLength(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
