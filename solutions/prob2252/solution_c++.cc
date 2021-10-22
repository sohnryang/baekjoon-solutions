/*
 * Baekjoon Online Judge #2252
 * https://www.acmicpc.net/problem/2252
 */

#include <ios>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N, M;
vector<int> sort_result;
unordered_set<int> visited, unvisited;
unordered_map<int, vector<int>> graph;

void dfs(int here) {
  visited.insert(here);
  unvisited.erase(here);
  for (auto there : graph[here])
    if (visited.count(there) == 0)
      dfs(there);
  sort_result.push_back(here);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i)
    unvisited.insert(i);
  for (int i = 0; i < M; ++i) {
    int A, B;
    cin >> A >> B;
    if (graph.count(B) == 0)
      graph[B] = {A};
    else
      graph[B].push_back(A);
  }

  while (!unvisited.empty()) {
    int start = *unvisited.begin();
    dfs(start);
  }

  for (auto result : sort_result)
    cout << result << " ";
  cout << "\n";
  return 0;
}
