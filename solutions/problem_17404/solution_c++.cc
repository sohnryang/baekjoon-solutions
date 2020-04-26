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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; ++i) cin >> C[i][0] >> C[i][1] >> C[i][2];

  for (int a = 0; a < 3; ++a) {
    for (int n = N - 1; n >= 0; --n) {
      if (n == 0) {
        int c1 = (a + 1) % 3, c2 = (a + 2) % 3;
        dp[a][a][0] = min(dp[a][c1][1], dp[a][c2][1]) + C[0][a];
        continue;
      }
      for (int b = 0; b < 3; ++b) {
        if (n == N - 1 && b == a) {
          dp[a][b][n] = numeric_limits<int>::max();
          continue;
        }
        int c1 = (b + 1) % 3, c2 = (b + 2) % 3;
        dp[a][b][n] = min(dp[a][c1][n + 1], dp[a][c2][n + 1]) + C[n][b];
      }
    }
  }

  cout << min(dp[0][0][0], min(dp[1][1][0], dp[2][2][0])) << '\n';
  return 0;
}
