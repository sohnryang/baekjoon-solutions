/*
 * Baekjoon Online Judge #1916
 * https://www.acmicpc.net/problem/1916
 */

#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using EdgeWeight = std::pair<bool, long long>;
const EdgeWeight INF = {true, 0};
int N, M, S, T;
std::vector<std::vector<std::pair<long long, int>>> G;

EdgeWeight operator+(const EdgeWeight &v1, long long v2) {
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

  std::vector<EdgeWeight> dist(N, INF);
  std::priority_queue<std::pair<EdgeWeight, int>,
                      std::vector<std::pair<EdgeWeight, int>>, std::greater<>>
      pq;
  pq.push({{false, 0}, S});
  while (!pq.empty()) {
    auto [here_dist, here] = pq.top();
    pq.pop();
    if (dist[here] <= here_dist)
      continue;
    dist[here] = here_dist;
    for (const auto &[there_weight, there] : G[here])
      pq.push({here_dist + there_weight, there});
  }
  std::cout << dist[T].second << "\n";

  return 0;
}
