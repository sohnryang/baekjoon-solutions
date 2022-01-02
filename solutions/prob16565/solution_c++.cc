/*
 * Baekjoon Online Judge #16565
 * https://www.acmicpc.net/problem/16565
 */

#include <cstring>
#include <ios>
#include <iostream>

using namespace std;

const int MOD = 10007;
int N, dp[13][53][2];

int cards(int i, int n, bool f) {
  if (n <= 0 || i == 13)
    return n == 0 && f;
  int &res = dp[i][n][f];
  if (res != -1)
    return res;
  res = cards(i + 1, n, f) + 4 * cards(i + 1, n - 1, f) +
        6 * cards(i + 1, n - 2, f) + 4 * cards(i + 1, n - 3, f) +
        cards(i + 1, n - 4, true);
  res %= MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof dp);
  cin >> N;
  cout << cards(0, N, false) << "\n";

  return 0;
}
