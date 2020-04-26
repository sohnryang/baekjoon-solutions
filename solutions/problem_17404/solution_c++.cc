/*
 * Baekjoon Online Judge #17404
 * https://www.acmicpc.net/problem/17404
 */

#include <algorithm>
#include <cstring>
#include <ios>
#include <iostream>
#include <numeric>

using namespace std;

const int MAX_N = 1000;
int N, C[MAX_N + 1][3], dp[3][3][MAX_N + 1];

int color_house(int a, int b, int n) {
  if (n == N) return 0;
  int &ret = dp[a][b][n];
  if (ret != -1) return ret;
  for (int i = 0; i < 3; ++i) {
    if (n == N - 2 && i == a) continue;
    if (i == b) continue;
    if (ret == -1)
      ret = color_house(a, i, n + 1);
    else
      ret = min(ret, color_house(a, i, n + 1));
  }
  ret += C[n][b];
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; ++i) cin >> C[i][0] >> C[i][1] >> C[i][2];

  memset(dp, -1, sizeof(dp));
  cout << min(color_house(0, 0, 0),
              min(color_house(1, 1, 0), color_house(2, 2, 0)))
       << '\n';
  return 0;
}
