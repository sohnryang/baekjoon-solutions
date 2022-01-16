/*
 * Baekjoon Online Judge #17626
 * https://www.acmicpc.net/problem/17626
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 50000;
int N, dp[MAX_N + 1];

int squares(int n) {
  int sqrted = sqrt(n);
  if (sqrted * sqrted == n)
    return n != 0;
  int &ret = dp[n];
  if (ret != -1)
    return ret;
  for (int i = 1; i <= sqrted; ++i) {
    if (ret == -1)
      ret = 1 + squares(n - i * i);
    else
      ret = min(ret, 1 + squares(n - i * i));
  }
  return ret;
}

int main() {
  scanf("%d", &N);
  memset(dp, -1, sizeof(dp));
  printf("%d\n", squares(N));
  return 0;
}
