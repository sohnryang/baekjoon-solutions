/*
 * Baekjoon Online Judge #14267
 * https://www.acmicpc.net/problem/14267
 */

#include <algorithm>
#include <cstdio>
#include <numeric>
#include <vector>

using namespace std;

int N, M, current_idx = -1;
vector<vector<int>> graph;
vector<int> range_lo, range_hi;

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

void dfs(int here) {
  range_lo[here] = ++current_idx;
  for (int there : graph[here]) {
    if (range_lo[there] != -1) continue;
    dfs(there);
  }
  range_hi[here] = current_idx;
}

int main() {
  scanf("%d %d", &N, &M);
  graph.resize(N);
  range_lo.assign(N, -1);
  range_hi.assign(N, -1);
  for (int i = 0; i < N; ++i) {
    int b;
    scanf("%d", &b);
    if (i == 0) continue;
    graph[b - 1].push_back(i);
  }
  dfs(0);
  RangeSum rsum(N);
  for (int i = 0; i < M; ++i) {
    int I, W;
    scanf("%d %d", &I, &W);
    I -= 1;
    rsum.update_range(range_lo[I], range_hi[I], W);
  }
  for (int i = 0; i < N; ++i)
    printf("%lld ", rsum.query(range_lo[i], range_lo[i]));
  printf("\n");
  return 0;
}
