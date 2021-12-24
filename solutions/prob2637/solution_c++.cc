/*
 * Baekjoon Online Judge #2637
 * https://www.acmicpc.net/problem/2637
 */

#include <ios>
#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX_N = 101;
int N, M;
unordered_map<int, int> graph[MAX_N];
unordered_map<int, int> res;
unordered_map<int, unordered_map<int, int>> dp;

inline bool is_terminal(int v) { return graph[v].size() == 0; }

void inc(unordered_map<int, int> &dict, int key, int val) {
  if (dict.count(key) == 0)
    dict[key] = 0;
  dict[key] += val;
}

void inc(unordered_map<int, int> &dict, unordered_map<int, int> &val,
         int mult) {
  for (auto [k, v] : val)
    inc(dict, k, v * mult);
}

void count_deps(int v) {
  if (dp.count(v) != 0)
    return;
  if (is_terminal(v))
    return;
  for (auto [u, c] : graph[v]) {
    if (!is_terminal(u)) {
      count_deps(u);
      inc(dp[v], dp[u], c);
    } else {
      inc(dp[v], u, c);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int X, Y, K;
    cin >> X >> Y >> K;
    graph[X][Y] = K;
  }
  count_deps(N);
  for (int i = 1; i <= N; ++i)
    if (is_terminal(i))
      cout << i << " " << dp[N][i] << "\n";
  return 0;
}
