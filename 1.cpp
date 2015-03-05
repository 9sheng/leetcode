#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        multimap<int, size_t> indexes;
        for (size_t i = 0; i < numbers.size(); i++) {
            indexes.insert(make_pair(numbers[i], i));
        }

        size_t i = 0;
        for (auto iter = indexes.begin(); iter != indexes.end(); ++iter) {
            numbers[i++] = (*iter).first;
        }

        for (size_t i = 0; i < numbers.size(); i++) {
            int value = target - numbers[i];
            if (binarySearch(numbers, i + 1, numbers.size() - 1, value)) {
                int m = 0;
                int n = 0;
                if (numbers[i] == value) {
                    auto iter = indexes.find(value);
                    m = iter->second;
                    iter++;
                    n = iter->second;
                } else {
                    m = indexes.find(value)->second;
                    n = indexes.find(numbers[i])->second;
                }
                m++;
                n++;
                return m < n ? vector<int>({m, n}) : vector<int>({n, m});
            }
        }

        return vector<int>();
    }

private:
    bool binarySearch(vector<int>& numbers, size_t low, size_t high, int target) {
        while (low <= high) {
            size_t mid = (low + high) / 2;
            if (numbers[mid] == target) {
                return true;
            } else if (numbers[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
