/*
 * Baekjoon Online Judge #5676
 * https://www.acmicpc.net/problem/5676
 */

#include <algorithm>
#include <cstdio>
#include <numeric>
#include <tuple>
#include <vector>

using namespace std;

struct elem_type {
  int negatives, zeroes, positives;
};

elem_type operator+(elem_type o1, elem_type o2) {
  elem_type ret = o1;
  ret.negatives += o2.negatives;
  ret.zeroes += o2.zeroes;
  ret.positives += o2.positives;
  return ret;
}

class Segtree {
 private:
  vector<elem_type> tree;
  int len;

  elem_type init_tree(vector<elem_type>& arr, int lo, int hi, int node) {
    if (lo == hi) return tree[node] = arr[lo];
    int mid = (lo + hi) / 2;
    auto left = init_tree(arr, lo, mid, node * 2);
    auto right = init_tree(arr, mid + 1, hi, node * 2 + 1);
    return tree[node] = left + right;
  }

  elem_type query(int lo, int hi, int node, int node_lo, int node_hi) {
    if (hi < node_lo || node_hi < lo) return {0, 0, 0};
    if (lo <= node_lo && node_hi <= hi) return tree[node];
    int mid = (node_lo + node_hi) / 2;
    return query(lo, hi, node * 2, node_lo, mid) +
           query(lo, hi, node * 2 + 1, mid + 1, node_hi);
  }

  elem_type update(int idx, elem_type newval, int node, int node_lo, int node_hi) {
    if (idx < node_lo || node_hi < idx) return tree[node];
    if (node_lo == node_hi) return tree[node] = newval;
    int mid = (node_lo + node_hi) / 2;
    return tree[node] = update(idx, newval, node * 2, node_lo, mid) +
                        update(idx, newval, node * 2 + 1, mid + 1, node_hi);
  }

 public:
  elem_type query(int lo, int hi) { return query(lo, hi, 1, 0, len - 1); }

  elem_type update(int idx, elem_type newval) {
    return update(idx, newval, 1, 0, len - 1);
  }

  Segtree(vector<elem_type>& arr) {
    len = arr.size();
    tree.resize(len * 4);
    init_tree(arr, 0, len - 1, 1);
  }
};

int N, K;
vector<elem_type> arr;

int main() {
  while (scanf("%d %d", &N, &K) != EOF) {
    arr.clear();
    for (int i = 0; i < N; ++i) {
      long long n;
      scanf("%lld", &n);
      if (n == 0) arr.push_back({0, 1, 0});
      else if (n > 0) arr.push_back({0, 0, 1});
      else arr.push_back({1, 0, 0});
    }
    Segtree tree(arr);
    for (int i = 0; i < K; ++i) {
      char c;
      getchar();
      scanf("%c", &c);
      if (c == 'C') {
        int I, V;
        scanf("%d %d", &I, &V);
        elem_type e = {0, 0, 0};
        if (V == 0) e.zeroes = 1;
        else if (V > 0) e.positives = 1;
        else e.negatives = 1;
        tree.update(I - 1, e);
      } else {
        int I, J;
        scanf("%d %d", &I, &J);
        auto result = tree.query(I - 1, J - 1);
        if (result.zeroes != 0) printf("0");
        else if (result.negatives % 2 == 0) printf("+");
        else printf("-");
      }
    }
    printf("\n");
  }
  return 0;
}
