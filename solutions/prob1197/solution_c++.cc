/*
 * Baekjoon Online Judge #1197
 * https://www.acmicpc.net/problem/1197
 */

#include <algorithm>
#include <ios>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

std::vector<int> parent_id, rank;
std::vector<std::pair<long long, std::pair<int, int>>> edges;
int V, E;

int find_set(int x) {
  if (x != parent_id[x]) {
    parent_id[x] = find_set(parent_id[x]);
  }
  return parent_id[x];
}

void union_set(int x, int y) {
  int root_x = find_set(x), root_y = find_set(y);
  if (root_x == root_y)
    return;
  if (rank[root_x] > rank[root_y])
    parent_id[root_y] = root_x;
  else {
    parent_id[root_x] = root_y;
    if (rank[root_x] == rank[root_y])
      rank[root_y]++;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> V >> E;
  parent_id.assign(V, 0);
  rank.assign(V, 0);
  std::iota(parent_id.begin(), parent_id.end(), 0);
  for (int i = 0; i < E; i++) {
    int A, B;
    long long C;
    std::cin >> A >> B >> C;
    A--;
    B--;
    edges.push_back({C, {A, B}});
  }
  std::sort(edges.begin(), edges.end());
  int res = 0;
  for (const auto &[weight, nodes] : edges) {
    const auto &[here, there] = nodes;
    if (find_set(here) == find_set(there))
      continue;
    union_set(here, there);
    res += weight;
  }
  std::cout << res << "\n";

  return 0;
}
