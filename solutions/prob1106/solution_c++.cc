/*
 * Baekjoon Online Judge #1106
 * https://www.acmicpc.net/problem/1106
 */

#include <algorithm>
#include <cstring>
#include <ios>
#include <iostream>

using namespace std;

const int MAX_C = 1001, MAX_N = 21, INF = 987654321;
int C, N, dp[MAX_N][MAX_C], costs[MAX_N], rewards[MAX_N];

int min_cost(int start_city, int goal) {
  if (goal <= 0)
    return 0;
  if (start_city == N)
    return INF;
  int &res = dp[start_city][goal];
  if (res != -1)
    return res;
  int x = 0;
  while (true) {
    int new_goal = goal - x * rewards[start_city];
    int curr = x * costs[start_city] + min_cost(start_city + 1, new_goal);
    res = res == -1 ? curr : min(res, curr);
    if (new_goal <= 0)
      break;
    x++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> C >> N;
  for (int i = 0; i < N; i++)
    cin >> costs[i] >> rewards[i];
  memset(dp, -1, sizeof(dp));
  cout << min_cost(0, C) << "\n";

  return 0;
}
