/*
 * Baekjoon Online Judge #2320
 * https://www.acmicpc.net/problem/2320
 */

#include <algorithm>
#include <cstring>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 17;
int N, dist[MAX_N][MAX_N], dp[MAX_N][1 << MAX_N];
string words[MAX_N];

int traverse(int here, int visited) {
  int &ret = dp[here][visited];
  if (ret != -1)
    return ret;
  ret = 0;
  for (int i = 0; i < N; ++i) {
    int mask = 1 << i;
    if (mask & visited)
      continue;
    if (!dist[here][i])
      continue;
    int visiting = mask | visited;
    ret = max(ret, traverse(i, visiting));
  }
  ret += words[here].length();
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> words[i];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      if (i == j)
        continue;
      dist[i][j] = words[i].back() == words[j].front();
      dist[j][i] = words[j].back() == words[i].front();
    }
  memset(dp, -1, sizeof(dp));
  int max_score = 0;
  for (int i = 0; i < N; i++)
    max_score = max(max_score, traverse(i, 1 << i));
  cout << max_score << "\n";

  return 0;
}
