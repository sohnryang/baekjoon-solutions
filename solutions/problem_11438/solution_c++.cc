/*
 * Baekjoon Online Judge #11438
 * https://www.acmicpc.net/problem/11438
 */

#include <ios>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

const int MAX_N = 1e5;
int N, M, depths[MAX_N + 1], parent[MAX_N + 1][21];
vector<int> graph[MAX_N + 1];
unordered_set<int> visited;

void dfs(int start, int depth) {
  visited.insert(start);
  depths[start] = depth;
  for (int child : graph[start]) {
    if (visited.count(child) != 0) continue;
    parent[child][0] = start;
    dfs(child, depth + 1);
  }
}

void process_parents() {
  for (int i = 1; i < 21; ++i)
    for (int j = 1; j <= N; ++j) parent[j][i] = parent[parent[j][i - 1]][i - 1];
}

int lca(int x, int y) {
  if (depths[x] > depths[y]) swap(x, y);
  for (int i = 20; i >= 0; --i)
    if (depths[y] - depths[x] >= (1 << i)) y = parent[y][i];
  if (x == y) return x;
  for (int i = 20; i >= 0; --i) {
    if (parent[x][i] != parent[y][i]) {
      x = parent[x][i];
      y = parent[y][i];
    }
  }
  return parent[x][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int A, B;
    cin >> A >> B;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  dfs(1, 0);
  process_parents();

  cin >> M;
  for (int i = 0; i < M; ++i) {
    int A, B;
    cin >> A >> B;
    cout << lca(A, B) << '\n';
  }

  return 0;
}
