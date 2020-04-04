/*
 * Baekjoon Online Judge #12895
 * https://www.acmicpc.net/problem/12895
 */

#include <cstdio>
#include <vector>

using namespace std;

class RangeSum {
 private:
  vector<long long> tree;
  vector<long long> lazy;
  int len;

  void update_lazy(int node, int lo, int hi) {
    if (lazy[node] == 0) return;
    tree[node] = lazy[node];
    if (lo != hi) {
      lazy[node * 2] = lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = 0;
  }

  long long query(int lo, int hi, int node, int node_lo, int node_hi) {
    update_lazy(node, node_lo, node_hi);
    if (hi < node_lo || node_hi < lo) return 0;
    if (lo <= node_lo && node_hi <= hi) return tree[node];
    int mid = (node_lo + node_hi) / 2;
    return query(lo, hi, node * 2, node_lo, mid) |
           query(lo, hi, node * 2 + 1, mid + 1, node_hi);
  }

  void update_range(int lo, int hi, long long delta, int node, int node_lo,
                    int node_hi) {
    update_lazy(node, node_lo, node_hi);
    if (hi < node_lo || lo > node_hi) return;
    if (lo <= node_lo && node_hi <= hi) {
      tree[node] = delta;
      if (node_lo != node_hi) {
        lazy[node * 2] = delta;
        lazy[node * 2 + 1] = delta;
      }
      return;
    }
    int mid = (node_lo + node_hi) / 2;
    update_range(lo, hi, delta, node * 2, node_lo, mid);
    update_range(lo, hi, delta, node * 2 + 1, mid + 1, node_hi);
    tree[node] = tree[node * 2] | tree[node * 2 + 1];
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

int N, T, Q;

int main() {
  scanf("%d %d %d", &N, &T, &Q);
  RangeSum rsum(N);
  rsum.update_range(0, N - 1, 1);
  for (int i = 0; i < Q; ++i) {
    char type;
    int x, y;
    scanf(" %c %d %d", &type, &x, &y);
    x--;
    y--;
    int lo = min(x, y);
    int hi = max(x, y);
    if (type == 'C') {
      int z;
      scanf("%d", &z);
      rsum.update_range(lo, hi, 1 << (z - 1));
    } else {
      printf("%d\n", __builtin_popcount(rsum.query(lo, hi)));
    }
  }
  return 0;
}
