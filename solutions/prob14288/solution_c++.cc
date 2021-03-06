/*
 * Baekjoon Online Judge #14288
 * https://www.acmicpc.net/problem/14288
 */

#include <algorithm>
#include <ios>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class RangeSum {
 private:
  vector<long long> tree;
  vector<long long> lazy;
  int len;

  void update_lazy(int node, int lo, int hi) {
    if (lazy[node] == 0) return;
    tree[node] += (hi - lo + 1) * lazy[node];
    if (lo != hi) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }

  long long query(int lo, int hi, int node, int node_lo, int node_hi) {
    update_lazy(node, node_lo, node_hi);
    if (hi < node_lo || node_hi < lo) return 0;
    if (lo <= node_lo && node_hi <= hi) return tree[node];
    int mid = (node_lo + node_hi) / 2;
    return query(lo, hi, node * 2, node_lo, mid) +
           query(lo, hi, node * 2 + 1, mid + 1, node_hi);
  }

  void update_range(int lo, int hi, long long delta, int node, int node_lo,
                    int node_hi) {
    update_lazy(node, node_lo, node_hi);
    if (hi < node_lo || lo > node_hi) return;
    if (lo <= node_lo && node_hi <= hi) {
      tree[node] += (node_hi - node_lo + 1) * delta;
      if (node_lo != node_hi) {
        lazy[node * 2] += delta;
        lazy[node * 2 + 1] += delta;
      }
      return;
    }
    int mid = (node_lo + node_hi) / 2;
    update_range(lo, hi, delta, node * 2, node_lo, mid);
    update_range(lo, hi, delta, node * 2 + 1, mid + 1, node_hi);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }

 public:
  long long query(int lo, int hi) { return query(lo, hi, 1, 0, len - 1); }

  void update_range(int lo, int hi, long long delta) {
    update_range(lo, hi, delta, 1, 0, len - 1);
  }

  RangeSum(int _len) {
    len = _len;
    tree.resize(len * 4);
    lazy.resize(len * 4);
  }
};

int N, M, current_idx = -1;
vector<vector<int>> graph;
vector<int> range_lo, range_hi;
bool downwards = true;

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
  RangeSum rsum1(N), rsum2(N);

  for (int i = 0; i < M; ++i) {
    int c;
    cin >> c;
    if (c == 1) {
      int I, W;
      cin >> I >> W;
      I--;
      if (downwards)
        rsum1.update_range(range_lo[I], range_hi[I], W);
      else
        rsum2.update_range(range_lo[I], range_lo[I], W);
    } else if (c == 2) {
      int I;
      cin >> I;
      I--;
      cout << rsum1.query(range_lo[I], range_lo[I]) +
                  rsum2.query(range_lo[I], range_hi[I])
           << '\n';
    } else {
      downwards = !downwards;
    }
  }
  return 0;
}
