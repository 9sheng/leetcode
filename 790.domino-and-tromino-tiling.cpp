/**
 * 790. Domino and Tromino Tiling
 *
 * We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.
 *
 * XX  <- domino
 *
 * XX  <- "L" tromino
 * X
 * Given N, how many ways are there to tile a 2 x N board? Return your answer modulo 10^9 + 7.
 *
 * (In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.)
 *
 * Example:
 * Input: 3
 * Output: 5
 * Explanation:
 * The five different ways are listed below, different letters indicates different tiles:
 * XYZ XXZ XYY XXY XYY
 * XYZ YYZ XZZ XYY XXY
 */

#include "testharness.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// 更高效的方法，将递归改为动态规划
// 按 0..n 计算 f、g 的值
class Solution {
 public:
  int numTilings(int n) {
    // return f(n);

    if (n < 3) return n;

    vector<long> fv(n+1), gv(n+1);
    fv[0] = 0;
    fv[1] = 1;
    fv[2] = 2;
    gv[0] = 0;
    gv[1] = 1;
    gv[2] = 2;

    for (int i = 3; i <= n; i++) {
      fv[i] = (fv[i-1] + fv[i-2] + 2*gv[i-2]) % MOD;
      gv[i] = (gv[i-1] + fv[i-1]) % MOD;
    }

    return fv[n];
  }

 private:
  long f(int n) {
    if (n <= 2) return n;

    auto iter = f_cache_.find(n);
    if (iter != f_cache_.end()) return iter->second;

    long ret = f(n-1) + f(n-2) + 2*g(n-2);
    if (ret > MOD) ret %= MOD;
    f_cache_[n] = ret;
    return ret;
  }

  // n: short leg length
  long g(int n) {
    if (n <= 2) return n;

    auto iter = g_cache_.find(n);
    if (iter != g_cache_.end()) {
      return iter->second;
    }

    long ret = g(n-1) + f(n-1);
    if (ret > MOD) ret %= MOD;
    g_cache_[n] = ret;
    return ret;
  }

 private:
  const int MOD = 1e9 + 7;
  map<int, long> f_cache_;
  map<int, long> g_cache_;
};

TEST(Solution, test) {
  ASSERT_EQ(01, numTilings(1));
  ASSERT_EQ(02, numTilings(2));
  ASSERT_EQ(05, numTilings(3));
  ASSERT_EQ(11, numTilings(4));
  ASSERT_EQ(24, numTilings(5));
  ASSERT_EQ(979232805, numTilings(1000));
}
