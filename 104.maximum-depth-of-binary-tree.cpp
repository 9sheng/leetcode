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
        int level;
    };

public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) return 0;

        queue<PathStatus> q;
        q.push({root, 1});
        int depth = 0;

        while (!q.empty()) {
            auto ps = q.front();
            q.pop();

            if (depth < ps.level) depth = ps.level;

            if (ps.node->left != NULL)
                q.push({ps.node->left, ps.level + 1});

            if (ps.node->right != NULL)
                q.push({ps.node->right, ps.level + 1});
        }

        return depth;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
