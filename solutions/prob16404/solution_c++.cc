/*
 * Baekjoon Online Judge #16404
 * https://www.acmicpc.net/problem/16404
 */

#include <algorithm>
#include <cstdio>
#include <numeric>
#include <vector>

using namespace std;

class RangeSum {
 private:
  vector<long long> tree;
  vector<long long> lazy;
  int len;

  long long init_tree(vector<long long>& arr, int lo, int hi, int node) {
    if (lo == hi) return tree[node] = arr[lo];
    int mid = (lo + hi) / 2;
    long long left = init_tree(arr, lo, mid, node * 2);
    long long right = init_tree(arr, mid + 1, hi, node * 2 + 1);
    return tree[node] = left + right;
  }

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

  RangeSum(vector<long long>& arr) {
    len = arr.size();
    tree.resize(len * 4);
    lazy.resize(len * 4);
    init_tree(arr, 0, len - 1, 1);
  }
};

int N, M, idx = 0;
vector<int> range_hi, range_lo;
vector<vector<int>> graph;

void dfs(int u) {
  range_lo[u] = idx;
  idx++;
  for (int v : graph[u]) dfs(v);
  range_hi[u] = idx;
}

int main() {
  scanf("%d %d", &N, &M);
  graph.resize(N);
  for (int i = 0; i < N; ++i) {
    int n;
    scanf("%d", &n);
    if (i == 0) continue;
    graph[n - 1].push_back(i);
  }
  range_lo.resize(N);
  range_hi.resize(N);
  dfs(0);
  vector<long long> arr(N);
  RangeSum rsum(arr);
  for (int i = 0; i < M; ++i) {
    int c;
    scanf("%d", &c);
    if (c == 1) {
      int I, W;
      scanf("%d %d", &I, &W);
      I--;
      rsum.update_range(range_lo[I], range_hi[I] - 1, W);
    } else {
      int I;
      scanf("%d", &I);
      I--;
      printf("%lld\n", rsum.query(range_lo[I], range_lo[I]));
    }
  }
  return 0;
}
