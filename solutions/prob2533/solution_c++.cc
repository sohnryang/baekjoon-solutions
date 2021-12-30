/*
 * Baekjoon Online Judge #2533
 * https://www.acmicpc.net/problem/2533
 */

#include <algorithm>
#include <cstring>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1'000'001;
int N, dp[MAX_N][2];
vector<int> graph[MAX_N], tree[MAX_N];

void dfs(int v) {
  for (int u : graph[v])
    if (tree[u].size() == 0) {
      tree[v].push_back(u);
      dfs(u);
    }
}

int f(int v, bool s) {
  if (!tree[v].size())
    return s;
  int &res = dp[v][s];
  if (res != -1)
    return res;
  res = s;
  for (int u : tree[v]) {
    if (s)
      res += min(f(u, false), f(u, true));
    else
      res += f(u, true);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i = 1; i < N; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  dfs(1);
  memset(dp, -1, sizeof dp);
  cout << min(f(1, false), f(1, true)) << "\n";

  return 0;
}
