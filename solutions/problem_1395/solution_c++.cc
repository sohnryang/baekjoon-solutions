/*
 * Baekjoon Online Judge #1395
 * https://www.acmicpc.net/problem/1395
 */

#include <algorithm>
#include <cstdio>
#include <numeric>
#include <vector>

using namespace std;

int N, M;

class Segtree {
 private:
  vector<long long> tree;
  vector<bool> lazy;
  int len;

  void update_lazy(int node, int lo, int hi) {
    if (lazy[node] == false) return;
    tree[node] = (hi - lo + 1) - tree[node];
    if (lo != hi) {
      lazy[node * 2] = !lazy[node * 2];
      lazy[node * 2 + 1] = !lazy[node * 2 + 1];
    }
    lazy[node] = false;
  }

  long long query(int lo, int hi, int node, int node_lo, int node_hi) {
    update_lazy(node, node_lo, node_hi);
    if (hi < node_lo || node_hi < lo) return 0;
    if (lo <= node_lo && node_hi <= hi) return tree[node];
    int mid = (node_lo + node_hi) / 2;
    return query(lo, hi, node * 2, node_lo, mid) +
           query(lo, hi, node * 2 + 1, mid + 1, node_hi);
  }

  void invert_range(int lo, int hi, int node, int node_lo, int node_hi) {
    update_lazy(node, node_lo, node_hi);
    if (hi < node_lo || lo > node_hi) return;
    if (lo <= node_lo && node_hi <= hi) {
      tree[node] = (node_hi - node_lo + 1) - tree[node];
      if (node_lo != node_hi) {
        lazy[node * 2] = !lazy[node * 2];
        lazy[node * 2 + 1] = !lazy[node * 2 + 1];
      }
      return;
    }
    int mid = (node_lo + node_hi) / 2;
    invert_range(lo, hi, node * 2, node_lo, mid);
    invert_range(lo, hi, node * 2 + 1, mid + 1, node_hi);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }

 public:
  long long query(int lo, int hi) { return query(lo, hi, 1, 0, len - 1); }

  void invert_range(int lo, int hi) {
    invert_range(lo, hi, 1, 0, len - 1);
  }

  Segtree(int _len) {
    len = _len;
    tree.resize(len * 4);
    lazy.resize(len * 4);
  }
};

int main() {
  scanf("%d %d", &N, &M);
  Segtree st(N);
  for (int i = 0; i < M; ++i) {
    int O, S, T;
    scanf("%d %d %d", &O, &S, &T);
    if (O == 0) st.invert_range(S - 1, T - 1);
    else printf("%lld\n", st.query(S - 1, T - 1));
  }
  return 0;
}
