#include "testharness.h"
#include <string>
#include <string.h>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL) return q == NULL;

        if (q == NULL) return false;
        
        return p->val == q->val &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
 