/*
 * Baekjoon Online Judge #11400
 * https://www.acmicpc.net/problem/11400
 */

#include <algorithm>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

int V, E, node_counter;
std::vector<std::vector<int>> graph;
std::vector<bool> visited;
std::vector<int> parents;
std::vector<int> node_ids, component_root_ids;
std::set<std::pair<int, int>> bridges;

void mark_components(int here) {
  visited[here] = true;
  node_ids[here] = node_counter++;
  component_root_ids[here] = node_ids[here];
  for (int i = 0; i < graph[here].size(); i++) {
    int there = graph[here][i];
    if (visited[there]) {
      if (parents[here] != there && component_root_ids[here] > node_ids[there])
        component_root_ids[here] = node_ids[there];
      continue;
    }
    parents[there] = here;
    mark_components(there);
    if (component_root_ids[here] > component_root_ids[there])
      component_root_ids[here] = component_root_ids[there];
  }
}

void collect_bridges(int here) {
  visited[here] = true;
  for (int i = 0; i < graph[here].size(); i++) {
    int there = graph[here][i];
    if (visited[there])
      continue;
    if (node_ids[here] < component_root_ids[there]) {
      auto edge = std::make_pair(std::min(here, there), std::max(here, there));
      bridges.insert(edge);
    }
    collect_bridges(there);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> V >> E;
  graph.assign(V, {});
  for (int i = 0; i < E; i++) {
    int A, B;
    std::cin >> A >> B;
    A--;
    B--;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  parents.assign(V, -1);
  visited.assign(V, false);
  node_counter = 0;
  node_ids.assign(V, -1);
  component_root_ids.assign(V, -1);
  mark_components(0);
  visited.assign(V, false);
  collect_bridges(0);
  std::vector<std::pair<int, int>> result(bridges.begin(), bridges.end());
  std::sort(result.begin(), result.end());
  std::cout << result.size() << "\n";
  for (const auto &p : result)
    std::cout << p.first + 1 << " " << p.second + 1 << "\n";
  return 0;
}
