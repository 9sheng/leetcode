// https://www.lintcode.com/problem/dices-sum/my-submissions
// Throw n dices, the sum of the dices' faces is S. Given n, find the all
// possible value of S along with its probability.

#include "testharness.h"
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

class Solution {
 public:
  /**
   * @param n an integer
   * @return a list of pair<sum, probability>
   */
  vector<pair<int, double>> dicesSum(int n) {
    cache_.resize(n);

    vector<pair<int, double>> ret;
    ret.reserve(5*n+1);
    for (int i = n; i <= (7*n+1)/2; i++) {
      ret.push_back(make_pair(i, count(n,i)));
    }
    for (int i = (7*n+1)/2+1; i <= 6*n; i++) {
      ret.push_back(make_pair(i, ret[6*n-i].second));
    }
    return ret;
  }

 private:
  // n times, sum equals to m
  double count(int n, int m) {
    if (n > m || m <= 0 || n <= 0) return 0.0;

    if (n == 1) {
      if (m > 0 && m < 7) return 1.0/6;
    }

    auto iter = cache_[n-1].find(m);
    if (iter != cache_[n-1].end()) {
      return iter->second;
    }

    double ret = 0.0;
    if (m > 1) {
      ret += count(n-1, m-1);
      if (m > 2) {
        ret += count(n-1, m-2);
        if (m > 3) {
          ret += count(n-1, m-3);
          if (m > 4) {
            ret += count(n-1, m-4);
            if (m > 5) {
              ret += count(n-1, m-5);
              if (m > 6) {
                ret += count(n-1, m-6);
              }
            }
          }
        }
      }
    }
    ret /= 6;

    cache_[n-1][m] = ret;
    return ret;
  }

 private:
  vector<map<int, double> > cache_;
};

TEST(Solution, test) {
  ASSERT_EQ(2, 1+1);

  for (long i = 1; i < 10; i++) {
    auto ret = dicesSum(i);
    for (auto iter = ret.begin(); iter != ret.end(); ++iter) {
      printf("%d  --> %.2f\n",  iter->first, iter->second);
    }
  }

}
