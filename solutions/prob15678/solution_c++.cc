/*
 * Baekjoon Online Judge #15678
 * https://www.acmicpc.net/problem/15678
 */

#include <algorithm>
#include <cstdio>
#include <deque>
#include <utility>

using namespace std;

const int MAX_N = 1e5, NEGINF = -987654321;
int N, D;
long long K[MAX_N + 1];
deque<pair<long long, int>> dq;

int main() {
  scanf("%d %d", &N, &D);
  long long current = 0, result = NEGINF;
  dq.push_back({0, 0});
  for (int i = 1; i <= N; ++i) {
    scanf("%lld", &K[i]);
    while (!dq.empty() && dq.front().second + D < i) dq.pop_front();
    current = max(K[i], K[i] + dq.front().first);
    result = max(result, current);
    while (!dq.empty() && dq.back().first <= current) dq.pop_back();
    dq.push_back({current, i});
  }
  printf("%lld\n", result);
  return 0;
}
