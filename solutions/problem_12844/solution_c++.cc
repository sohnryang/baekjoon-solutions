/*
 * Baekjoon Online Judge #12844
 * https://www.acmicpc.net/problem/12844
 */

#include <algorithm>
#include <cstdio>
#include <numeric>
#include <vector>

using namespace std;

int N, M, K;
vector<long long> arr;

class RangeXORSum {
 private:
  vector<long long> tree;
  vector<long long> lazy;
  int len;

  long long init_tree(vector<long long>& arr, int lo, int hi, int node) {
    if (lo == hi) return tree[node] = arr[lo];
    int mid = (lo + hi) / 2;
    long long left = init_tree(arr, lo, mid, node * 2);
    long long right = init_tree(arr, mid + 1, hi, node * 2 + 1);
    return tree[node] = left ^ right;
  }

  void update_lazy(int node, int lo, int hi) {
    if (lazy[node] == 0) return;
    if ((hi - lo + 1) % 2 == 1) tree[node] ^= lazy[node];
    if (lo != hi) {
      lazy[node * 2] ^= lazy[node];
      lazy[node * 2 + 1] ^= lazy[node];
    }
    lazy[node] = 0;
  }

  long long query(int lo, int hi, int node, int node_lo, int node_hi) {
    update_lazy(node, node_lo, node_hi);
    if (hi < node_lo || node_hi < lo) return 0;
    if (lo <= node_lo && node_hi <= hi) return tree[node];
    int mid = (node_lo + node_hi) / 2;
    return query(lo, hi, node * 2, node_lo, mid) ^
           query(lo, hi, node * 2 + 1, mid + 1, node_hi);
  }

  void update_range(int lo, int hi, long long delta, int node, int node_lo,
                    int node_hi) {
    update_lazy(node, node_lo, node_hi);
    if (hi < node_lo || lo > node_hi) return;
    if (lo <= node_lo && node_hi <= hi) {
      if ((node_hi - node_lo + 1) % 2 == 1) tree[node] ^= delta;
      if (node_lo != node_hi) {
        lazy[node * 2] ^= delta;
        lazy[node * 2 + 1] ^= delta;
      }
      return;
    }
    int mid = (node_lo + node_hi) / 2;
    update_range(lo, hi, delta, node * 2, node_lo, mid);
    update_range(lo, hi, delta, node * 2 + 1, mid + 1, node_hi);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
  }

 public:
  long long query(int lo, int hi) { return query(lo, hi, 1, 0, len - 1); }

  void update_range(int lo, int hi, long long delta) {
    update_range(lo, hi, delta, 1, 0, len - 1);
  }

  RangeXORSum(vector<long long>& arr) {
    len = arr.size();
    tree.resize(len * 4);
    lazy.resize(len * 4);
    init_tree(arr, 0, len - 1, 1);
  }
};

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    long long n;
    scanf("%lld", &n);
    arr.push_back(n);
  }
  RangeXORSum rsum(arr);
  scanf("%d", &M);
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (b > c) {
      int t = b;
      b = c;
      c = t;
    }
    if (a == 1) {
      long long d;
      scanf("%lld", &d);
      rsum.update_range(b, c, d);
    } else {
      printf("%lld\n", rsum.query(b, c));
    }
  }
  return 0;
}
