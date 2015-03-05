#include "testharness.h"
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
       size_t size = num.size();
       if (size < 2) return 0;

       sort(num.begin(), num.end(), myobject);

       int max = num[1] - num[0];
       for (size_t i = 1; i < size - 1; i++) {
           int tmp = num[i+1] - num[i];
           if (max < tmp) max = tmp;
       }
       return max;
    }

private:

struct myclass {
    bool operator() (int i, int j) { return i < j; }
} myobject;

};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
