/*
 * Baekjoon Online Judge #11779
 * https://www.acmicpc.net/problem/11779
 */

#include <algorithm>
#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using PathCost = std::pair<bool, long long>;
const PathCost INF = {true, 0};
int N, M, S, T;
std::vector<std::vector<std::pair<long long, int>>> G;

PathCost operator+(const PathCost &v1, long long v2) {
  if (v1.first)
    return INF;
  return {v1.first, v1.second + v2};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;
  G.assign(N, {});
  for (int i = 0; i < M; i++) {
    int A, B;
    long long W;
    std::cin >> A >> B >> W;
    A--;
    B--;
    G[A].push_back({W, B});
  }
  std::cin >> S >> T;
  S--;
  T--;
  std::vector<PathCost> dist(N, INF);
  std::vector<int> parent(N, -1);
  std::priority_queue<std::tuple<PathCost, int, int>,
                      std::vector<std::tuple<PathCost, int, int>>,
                      std::greater<>>
      pq;
  pq.push({{false, 0}, S, S});
  while (!pq.empty()) {
    auto [here_cost, here, here_parent] = pq.top();
    pq.pop();
    if (dist[here] <= here_cost)
      continue;
    dist[here] = here_cost;
    parent[here] = here_parent;
    for (const auto &[there_weight, there] : G[here]) {
      pq.push({here_cost + there_weight, there, here});
    }
  }
  std::cout << dist[T].second << "\n";
  std::vector<int> path;
  int here = T;
  while (here != S) {
    path.push_back(here);
    here = parent[here];
  }
  path.push_back(S);
  std::cout << path.size() << "\n";
  std::reverse(path.begin(), path.end());
  for (const auto &v : path)
    std::cout << v + 1 << " ";
  std::cout << "\n";

  return 0;
}
