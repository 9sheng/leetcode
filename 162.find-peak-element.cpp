#include "testharness.h"
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        size_t high = num.size() - 1;
        size_t low = 0;

        while (high - low > 1) {
            size_t mid = (low + high) / 2;
            if (num[mid] < num[mid+1])
                low = mid + 1;
            else if (num[mid] < num[mid-1])
                high = mid - 1;
            else
                return mid;
        }

        size_t max = low;
        for (size_t i = low + 1; i <= high; i++) {
            if (num[max] < num[i])
                max = i;
        }

        return max;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
