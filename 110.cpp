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
    bool isBalanced(TreeNode *root) {
        
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
