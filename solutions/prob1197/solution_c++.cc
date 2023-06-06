/*
 * Baekjoon Online Judge #1197
 * https://www.acmicpc.net/problem/1197
 */

#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int V, E;
std::vector<std::vector<std::pair<long long, int>>> G;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> V >> E;
  G.assign(V, {});
  for (int i = 0; i < E; i++) {
    int A, B;
    long long C;
    std::cin >> A >> B >> C;
    A--;
    B--;
    G[A].push_back({C, B});
    G[B].push_back({C, A});
  }
  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int>>, std::greater<>>
      pq;
  int tree_cost = 0;
  std::vector<bool> visited(V, false);
  auto mark_node = [&pq, &visited](int here) {
    visited[here] = true;
    for (const auto &[there_weight, there] : G[here]) {
      if (visited[there])
        continue;
      pq.push({there_weight, there});
    }
  };
  mark_node(0);
  while (!pq.empty()) {
    auto [here_weight, here] = pq.top();
    pq.pop();
    if (visited[here])
      continue;
    tree_cost += here_weight;
    mark_node(here);
  }
  std::cout << tree_cost << "\n";

  return 0;
}
