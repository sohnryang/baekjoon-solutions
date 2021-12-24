/*
 * Baekjoon Online Judge #2629
 * https://www.acmicpc.net/problem/2629
 */

#include <ios>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

const int MAX_N = 30;
int N, M, A[MAX_N];
map<pair<int, int>, bool> dp;

bool check(int w, int idx) {
  if (idx >= N)
    return w == 0;
  if (dp.count({w, idx}))
    return dp[{w, idx}];
  bool res = check(w + A[idx], idx + 1) || check(w, idx + 1) ||
             check(w - A[idx], idx + 1);
  dp[{w, idx}] = res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> A[i];
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int W;
    cin >> W;
    cout << (check(W, 0) ? "Y" : "N") << " ";
  }

  return 0;
}
