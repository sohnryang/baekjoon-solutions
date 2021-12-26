/*
 * Baekjoon Online Judge #11570
 * https://www.acmicpc.net/problem/11570
 */

#include <algorithm>
#include <cmath>
#include <cstring>
#include <ios>
#include <iostream>

using namespace std;

const int MAX_N = 2001;
int N, A[MAX_N], dp[MAX_N][MAX_N];

int cost(int i, int j) {
  if (j > N)
    return 0;
  int &res = dp[i][j];
  if (res != -1)
    return res;
  res = min(abs(A[i == 0 ? j : i] - A[j]) + cost(j - 1, j + 1),
            abs(A[j - 1] - A[j]) + cost(i, j + 1));
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; ++i)
    cin >> A[i];
  memset(dp, -1, sizeof dp);
  cout << cost(0, 1) << "\n";
  return 0;
}
