#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <stack>

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
        int sum;
    };

public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;

        stack<PathStatus> s;
        s.push({root, root->val});

        while (!s.empty()) {
            auto ps = s.top();
            s.pop();

            if (ps.node->left == NULL && ps.node->right == NULL && ps.sum == sum)
                return true;

            if (ps.node->left != NULL)
                s.push({ps.node->left, ps.sum + ps.node->left->val});

            if (ps.node->right != NULL)
                s.push({ps.node->right, ps.sum + ps.node->right->val});


        }

        return false;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
