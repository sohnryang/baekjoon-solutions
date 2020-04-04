/*
 * Baekjoon Online Judge #13261
 * https://www.acmicpc.net/problem/13261
 */

#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_L = 8'000, MAX_G = 800;
int L, G, C[MAX_L + 1];
long long psum[MAX_L + 1], dp[MAX_G + 1][MAX_L + 1], p[MAX_G + 1][MAX_L + 1];

long long cost(int left, int right) {
  return (psum[right] - psum[left - 1]) * (right - left + 1);
}

void jailbreak(int start, int left, int right, int range_lo, int range_hi) {
  if (left > right) return;
  int mid = (left + right) / 2;
  dp[start][mid] = -1;
  p[start][mid] = -1;
  for (int i = range_lo; i <= range_hi; ++i) {
    long long current = dp[start - 1][i] + cost(i + 1, mid);
    if (dp[start][mid] == -1 || dp[start][mid] > current) {
      dp[start][mid] = current;
      p[start][mid] = i;
    }
  }
  jailbreak(start, left, mid - 1, range_lo, p[start][mid]);
  jailbreak(start, mid + 1, right, p[start][mid], range_hi);
}

int main() {
  scanf("%d %d", &L, &G);
  C[0] = 0;
  for (int i = 1; i <= L; ++i) {
    scanf("%d", &C[i]);
    psum[i] = psum[i - 1] + C[i];
  }
  for (int i = 0; i <= L; ++i) {
    dp[1][i] = cost(1, i);
    p[1][i] = 0;
  }
  for (int i = 2; i <= G; ++i) jailbreak(i, 0, L, 0, L);
  printf("%lld\n", dp[G][L]);
  return 0;
}
