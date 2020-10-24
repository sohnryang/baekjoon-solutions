/*
 * Baekjoon Online Judge #11049
 * acmicpc.net/problem/11049
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

const int MAX_N = 500, INF = 987654321;
int N, dp[MAX_N + 1][MAX_N + 1], matrices[MAX_N + 2];

int mult(int start, int end) {
  if (start == end) return 0;
  int &ret = dp[start][end];
  if (ret != -1) return ret;
  ret = INF;
  for (int i = start; i < end; ++i) {
    ret = min(
      ret,
      mult(start, i) + mult(i + 1, end) + \
      matrices[start - 1] * matrices[i] * matrices[end]
    );
  }
  return ret;
}

int main() {
  scanf("%d", &N);
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < N; ++i) {
    int r, c;
    scanf("%d %d", &r, &c);
    if (i == 0) matrices[0] = r;
    matrices[i + 1] = c;
  }
  printf("%d\n", mult(1, N));
  return 0;
}
