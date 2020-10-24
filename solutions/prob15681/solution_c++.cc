/*
 * Baekjoon Online Judge #15681
 * https://www.acmicpc.net/problem/15681
 */

#include <cstring>
#include <ios>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX_N = 1e5;
int N, R, Q, dp[MAX_N + 1];
vector<int> graph[MAX_N + 1], tree[MAX_N + 1];
unordered_set<int> visited;

void dfs(int start, int parent) {
  visited.insert(start);
  for (int child : graph[start])
    if (child != parent && visited.count(child) == 0)
      tree[start].push_back(child), dfs(child, start);
}

int query(int root) {
  int &ret = dp[root];
  if (ret != -1) return ret;
  ret = 1;
  for (int child : tree[root]) ret += query(child);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> R >> Q;
  for (int i = 0; i < N - 1; ++i) {
    int U, V;
    cin >> U >> V;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }
  dfs(R, 0);
#ifdef DEBUG
  for (int i = 1; i <= N; ++i) {
    for (int child : tree[i]) cout << child << ' ';
    cout << '\n';
  }
#endif
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < Q; ++i) {
    int U;
    cin >> U;
    cout << query(U) << '\n';
  }
  return 0;
}
