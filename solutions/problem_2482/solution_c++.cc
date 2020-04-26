/*
 * Baekjoon Online Judge #2482
 * https://www.acmicpc.net/problem/2482
 */

#include <cstring>
#include <ios>
#include <iostream>

using namespace std;

const int MOD = 1e9 + 3, MAX_N = 1000;
int N, K, dp[MAX_N + 1][MAX_N + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> K;

  for (int i = 0; i <= N; ++i) {
    dp[i][0] = 1;
    dp[i][1] = i;
  }
  for (int i = 2; i <= N; ++i)
    for (int j = 2; j <= K; ++j)
      dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;

  cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % MOD << '\n';
  return 0;
}
