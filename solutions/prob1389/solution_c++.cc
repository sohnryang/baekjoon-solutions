/*
 * Baekjoon Online Judge #1389
 * https://www.acmicpc.net/problem/1389
 */

#include <algorithm>
#include <ios>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <utility>

using namespace std;

const int MAX_N = 100;
int N, M;
set<int> graph[MAX_N + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    graph[A].insert(B);
    graph[B].insert(A);
  }

  pair<int, int> res(numeric_limits<int>::max(), 0);
  for (int src = 1; src <= N; src++) {
    int dist[MAX_N + 1] = {0};
    dist[src] = 0;
    queue<pair<int, int>> q;
    q.push({0, src});
    while (!q.empty()) {
      auto [here_dist, here] = q.front();
      q.pop();
      for (auto there : graph[here]) {
        if (dist[there] != 0)
          continue;
        dist[there] = here_dist + 1;
        q.push({dist[there], there});
      }
    }
    int num = 0;
    for (int dst = 1; dst <= N; dst++)
      num += dist[dst];
    res = min(res, {num, src});
  }
  cout << res.second << "\n";

  return 0;
}
