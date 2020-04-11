/*
 * Baekjoon Online Judge #13262
 * https://www.acmicpc.net/problem/13262
 */

#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 5000;
int N, K, A[MAX_N + 1], cost[MAX_N + 1][MAX_N + 1], p[MAX_N + 1][MAX_N + 1];
long long dp[MAX_N + 1][MAX_N + 1];

void dnc(int t, int l, int r, int pl, int pr) {
  if (l > r) return;
  int mid = (l + r) / 2;
  p[t][mid] = -1;
  dp[t][mid] = -1;

  long long current;
  for (int k = pl; k <= min(pr, mid); ++k) {
    current = dp[t - 1][k - 1] + cost[k][mid];
    if (dp[t][mid] < current) {
      dp[t][mid] = current;
      p[t][mid] = k;
    }
  }

  dnc(t, l, mid - 1, pl, p[t][mid]);
  dnc(t, mid + 1, r, p[t][mid], pr);
}

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
  }
  for (int i = 1; i <= N; ++i) {
    cost[i][i] = A[i];
    for (int j = i + 1; j <= N; ++j) cost[i][j] = cost[i][j - 1] | A[j];
  }
  for (int i = 1; i <= N; ++i) {
    dp[1][i] = cost[1][i];
    p[1][i] = 1;
  }
  for (int i = 2; i <= K; ++i) dnc(i, i, N, i, N);
  printf("%lld\n", dp[K][N]);
  return 0;
}
