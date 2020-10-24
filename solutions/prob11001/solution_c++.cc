/*
 * Baekjoon Online Judge #11001
 * https://www.acmicpc.net/problem/11001
 */

#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX_N = 100000;
int N, D;
long long T[MAX_N + 1], V[MAX_N + 1], result;

long long value(long long pushdate, long long popdate) {
  return (popdate - pushdate) * T[popdate] + V[pushdate];
}

void dnc_opt(int start, int end, int left, int right) {
  if (start > end) return;
  int mid = (start + end) / 2;
  int k = max(left, mid - D);
  for (int i = k; i <= min(mid, right); ++i) {
    if (value(k, mid) < value(i, mid)) k = i;
  }
  result = max(result, value(k, mid));
  dnc_opt(start, mid - 1, left, k);
  dnc_opt(mid + 1, end, k, right);
}

int main() {
  scanf("%d %d", &N, &D);
  for (int i = 1; i <= N; ++i) scanf("%lld", &T[i]);
  for (int i = 1; i <= N; ++i) scanf("%lld", &V[i]);
  dnc_opt(1, N, 1, N);
  printf("%lld\n", result);
  return 0;
}
