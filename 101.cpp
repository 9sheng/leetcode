#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    struct PathStatus {
        TreeNode* node;
        int tag;
    };

public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;

        queue<PathStatus> ql;
        queue<PathStatus> qr;

        if (root->left == NULL && root->right == NULL) return true;
        if (root->left == NULL || root->right == NULL) return false;

        ql.push({root->left, 1});
        qr.push({root->right, 1});

        while (!ql.empty() && !qr.empty()) {
            auto l = ql.front();
            auto r = qr.front();
            ql.pop();
            qr.pop();

            if (l.tag != r.tag || l.node->val != r.node->val) return false;

            if (l.node->left != NULL) ql.push({l.node->left, 2 * l.tag - 1});
            if (l.node->right != NULL) ql.push({l.node->right, 2 * l.tag + 1});

            if (r.node->right != NULL) qr.push({r.node->right, 2 * r.tag - 1});
            if (r.node->left != NULL) qr.push({r.node->left, 2 * r.tag + 1});

        }

        return ql.empty() && qr.empty();
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
