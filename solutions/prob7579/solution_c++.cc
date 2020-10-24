/*
 * Baekjoon Online Judge #7579
 * https://www.acmicpc.net/problem/7579
 */

#include <algorithm>
#include <cstring>
#include <ios>
#include <iostream>

using namespace std;

const int MAX_N = 100, MAX_COST = 10000;
int N, M, mem[MAX_N + 1], cost[MAX_N + 1], dp[MAX_N + 1][MAX_COST + 1];

int kill_app(int nth, int available_cost) {
  if (nth >= N) return 0;
  int &ret = dp[nth][available_cost];
  if (ret != -1) return ret;
  ret = kill_app(nth + 1, available_cost);
  if (cost[nth] <= available_cost)
    ret = max(mem[nth] + kill_app(nth + 1, available_cost - cost[nth]), ret);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 0; i < N; ++i) cin >> mem[i];
  for (int i = 0; i < N; ++i) cin >> cost[i];
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= MAX_COST; ++i) {
    int result = kill_app(0, i);
    if (result < M) continue;
    cout << i << '\n';
    break;
  }
  return 0;
}
