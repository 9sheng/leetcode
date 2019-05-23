#include "testharness.h"
#include <string>
#include <string.h>
#include <vector>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        if (head == NULL) return NULL;

        // step1: duplicate nodes
        RandomListNode* current = head;
        while (current != NULL) {
            RandomListNode* dup = new RandomListNode(current->label);
            dup->next = current->next;
            current->next = dup;
            current = dup->next;
        }

        // step2: set random pointers
        current = head;
        while (current != NULL) {
            if (current->random != NULL) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // step3: split lists
        RandomListNode* newHead = head->next;
        current = head;
        while (current != NULL) {
            RandomListNode* current2= current->next;
            current->next = current2->next;
            if (current2->next != NULL) {
                current2->next = current2->next->next;
            }
            current = current->next;
        }

        return newHead;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
