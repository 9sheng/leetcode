#include "testharness.h"
#include <unordered_map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;

        std::unordered_map<TreeNode*, int> treeHight;
        treeHight[NULL] = 0;

        std::stack<TreeNode*> s;
        s.push({root});

        while (!s.empty()) {
            auto ps = s.top();

            int lh = -1;
            int rh = -1;
            auto lt = treeHight.find(ps->left);
            if (lt != treeHight.end()) {
                lh = (*lt).second;
            } else {
                s.push({ps->left});
            }

            auto rt = treeHight.find(ps->right);
            if (rt != treeHight.end()) {
                rh = (*rt).second;
            } else {
                s.push({ps->right});
            }

            if (lh >= 0 && rh >= 0) {
                if (lh > rh + 1 || rh > lh + 1) return false;

                s.pop();
                treeHight[ps] = (lh > rh ? lh : rh) + 1;
            }
        }

        return true;
    }
};


TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
    TreeNode root(1);
    TreeNode n11(1);
    TreeNode n12(1);
    TreeNode n21(1);
    TreeNode n22(1);
    TreeNode n23(1);
    TreeNode n24(1);

    root.left = &n11;
    root.right = &n12;
    ASSERT_EQ(true, isBalanced(&root));
    n11.left = &n21;
    ASSERT_EQ(true, isBalanced(&root));
    n21.left = &n22;
    ASSERT_EQ(false, isBalanced(&root));
    n11.right = &n23;
    ASSERT_EQ(false, isBalanced(&root));
}
