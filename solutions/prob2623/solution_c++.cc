/*
 * Baekjoon Online Judge #2623
 * https://www.acmicpc.net/problem/2623
 */

#include <ios>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int N, M;
bool cycle_detected = false;
vector<vector<int>> graph;
vector<int> visited;
list<int> sorted;

void dfs(int s) {
  if (visited[s]) {
    if (visited[s] == 1)
      cycle_detected = true;
    return;
  }
  visited[s] = 1;
  for (auto u : graph[s])
    dfs(u);
  visited[s] = 2;
  sorted.push_front(s);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  graph.assign(N + 1, {});
  visited.assign(N + 1, 0);
  for (int i = 0; i < M; ++i) {
    int K, last;
    cin >> K >> last;
    for (int j = 1; j < K; ++j) {
      int x;
      cin >> x;
      graph[last].push_back(x);
      last = x;
    }
  }
  for (int i = 1; i <= N; ++i)
    dfs(i);
  if (cycle_detected)
    cout << "0\n";
  else {
    for (auto x : sorted) {
      cout << x << "\n";
    }
  }
}
