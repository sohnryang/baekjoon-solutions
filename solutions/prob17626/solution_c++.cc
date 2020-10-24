/*
 * Baekjoon Online Judge #17626
 * https://www.acmicpc.net/problem/17626
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int INF = 987654321, MAX_N = 50000;
int N, dp[MAX_N];

int squares(int n) {
  int sqrted = sqrt(n);
  if (sqrted * sqrted == n) return 1;
  int &ret = dp[n];
  if (ret != -1) return ret;
  ret = INF;
  for (int i = 1; i <= sqrted; ++i)
    ret = min(ret, 1 + squares(n - i * i));
  return ret;
}

int main() {
  scanf("%d", &N);
  memset(dp, -1, sizeof(dp));
  printf("%d\n", squares(N));
  return 0;
}
