/*
 * Baekjoon Online Judge #5869
 * https://www.acmicpc.net/problem/5869
 */

#include <cstring>
#include <ios>
#include <iostream>

using namespace std;

const int MAX_LEN = 1001, MOD = 2012;
char S[MAX_LEN];
int N, openings_before[MAX_LEN], dp[MAX_LEN][MAX_LEN];

int f(int i, int j) {
  if (i == N)
    return 1;
  int &res = dp[i][j];
  if (res != -1)
    return res;
  res = 0;
  if (S[i] == '(') {
    res += f(i + 1, j);
    res += f(i + 1, j + 1);
  } else {
    if (j > 0)
      res += f(i + 1, j - 1);
    if (openings_before[i] - j > 0)
      res += f(i + 1, j);
  }
  res %= MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> S;
  N = strlen(S);
  memset(dp, -1, sizeof dp);
  for (int i = 1; i < N; ++i) {
    openings_before[i] = openings_before[i - 1];
    if (S[i - 1] == '(')
      openings_before[i]++;
    else
      openings_before[i]--;
  }
  cout << f(0, 0) << "\n";

  return 0;
}
