#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;

        ListNode* prevNode = head;
        int prevVal = prevNode->val;
        ListNode* currentNode = head->next;

        while (currentNode != NULL) {
            if (currentNode->val == prevVal) {
                prevNode->next = currentNode->next;
                delete currentNode;
            } else {
                prevVal = currentNode->val;
                prevNode = currentNode;
            }
            currentNode = prevNode->next;
        }

        return head;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
