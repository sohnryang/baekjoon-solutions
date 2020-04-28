/*
 * Baekjoon Online Judge #14287
 * https://www.acmicpc.net/problem/14287
 */

#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int N, M, current_idx = -1;
vector<vector<int>> graph;
vector<int> range_lo, range_hi;

class FenwickTree {
 private:
  vector<int> tree;

 public:
  FenwickTree(int n) : tree(n + 1) {}

  int range_sum(int pos) {
    ++pos;
    int ret = 0;
    while (pos > 0) {
      ret += tree[pos];
      pos &= (pos - 1);
    }
    return ret;
  }

  void update(int pos, int val) {
    ++pos;
    while (pos < tree.size()) {
      tree[pos] += val;
      pos += (pos & -pos);
    }
  }
};

void dfs(int here) {
  range_lo[here] = ++current_idx;
  for (int there : graph[here]) {
    if (range_lo[there] != -1) continue;
    dfs(there);
  }
  range_hi[here] = current_idx;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  graph.resize(N);
  range_lo.assign(N, -1);
  range_hi.assign(N, -1);
  for (int i = 0; i < N; ++i) {
    int b;
    cin >> b;
    if (i == 0) continue;
    graph[b - 1].push_back(i);
  }
  dfs(0);
  FenwickTree rsum(N);
  for (int i = 0; i < M; ++i) {
    int c;
    cin >> c;
    if (c == 1) {
      int I, W;
      cin >> I >> W;
      I -= 1;
      rsum.update(range_lo[I], W);
    } else {
      int I;
      cin >> I;
      I -= 1;
      cout << rsum.range_sum(range_hi[I]) - rsum.range_sum(range_lo[I] - 1)
           << '\n';
    }
  }
  return 0;
}
