/*
 * Baekjoon Online Judge #1649
 * https://www.acmicpc.net/problem/1649
 */

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <ios>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

int T, N, M, S, E, K;
int64_t cache[4001][4001];
std::vector<std::vector<int>> graph;
std::vector<int> topological_sorted, visit_order;
std::vector<bool> visited;
std::unordered_set<int> D;

void dfs(int here) {
  visited[here] = true;
  for (const auto &there : graph[here]) {
    if (visited[there])
      continue;
    dfs(there);
  }
  topological_sorted.push_back(here);
}

int64_t count_paths(int here, int dest) {
  int64_t &res = cache[here][dest];
  if (res != -1)
    return res;
  if (here == dest)
    return 1;
  res = 0;
  for (const auto &there : graph[here]) {
    res += count_paths(there, dest);
  }
  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> N >> M;
  graph.assign(N, {});
  for (int i = 0; i < M; i++) {
    int U, V;
    std::cin >> U >> V;
    U--;
    V--;
    graph[U].push_back(V);
  }
  std::cin >> S >> E >> K;
  S--;
  E--;
  memset(cache, -1, sizeof(cache));
  if (K == 0) {
    std::cout << count_paths(S, E) << '\n';
    return 0;
  }
  D.clear();
  for (int i = 0; i < K; i++) {
    int d;
    std::cin >> d;
    d--;
    D.insert(d);
  }
  visited.assign(N, false);
  dfs(S);
  std::reverse(topological_sorted.begin(), topological_sorted.end());
  visit_order.clear();
  for (const auto &node : topological_sorted)
    if (D.count(node))
      visit_order.push_back(node);
  if (visit_order.size() != K) {
    std::cout << "0\n";
    return 0;
  }
  int64_t res = count_paths(S, visit_order[0]);
  for (int i = 1; i < visit_order.size(); i++) {
    int src = visit_order[i - 1], dest = visit_order[i];
    res *= count_paths(src, dest);
  }
  res *= count_paths(visit_order.back(), E);
  std::cout << res << '\n';
  return 0;
}
