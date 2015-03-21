#include "testharness.h"
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        int num = 1;
        int level = 0;
        std::queue<TreeNode*> q;
        q.push(root);

        while (not q.empty()) {
            result.push_back(vector<int>());
            int tmpNum = 0;
            for (size_t i = 0; i < num; ++i) {
                auto t = q.front();
                q.pop();
                result.back().push_back(t->val);

                if (t->left != NULL) {
                    q.push(t->left);
                    ++tmpNum;
                }
                if (t->right != NULL) {
                    q.push(t->right);
                    ++tmpNum;
                }
            }
            num = tmpNum;
            ++level;
        }

        return result;
    }
};
TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
