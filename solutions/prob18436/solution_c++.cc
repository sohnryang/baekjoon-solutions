/*
 * Baekjoon Online Judge #18436
 * https://www.acmicpc.net/problem/18436
 */

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

class SegTree {
 private:
  vector<int> tree;
  int len;

  int init_tree(vector<int>& arr, int lo, int hi, int node) {
    if (lo == hi) return tree[node] = arr[lo] % 2;
    int mid = (lo + hi) / 2;
    int left = init_tree(arr, lo, mid, node * 2);
    int right = init_tree(arr, mid + 1, hi, node * 2 + 1);
    return tree[node] = left + right;
  }

  int query(int lo, int hi, int node, int node_lo, int node_hi) {
    if (hi < node_lo || node_hi < lo) return 0;
    if (lo <= node_lo && node_hi <= hi) return tree[node];
    int mid = (node_lo + node_hi) / 2;
    return query(lo, hi, node * 2, node_lo, mid) +
           query(lo, hi, node * 2 + 1, mid + 1, node_hi);
  }

  int update(int idx, int newval, int node, int node_lo, int node_hi) {
    if (idx < node_lo || node_hi < idx) return tree[node];
    if (node_lo == node_hi) return tree[node] = newval % 2;
    int mid = (node_lo + node_hi) / 2;
    return tree[node] = update(idx, newval, node * 2, node_lo, mid) +
                        update(idx, newval, node * 2 + 1, mid + 1, node_hi);
  }

 public:
  int query(int lo, int hi) { return query(lo, hi, 1, 0, len - 1); }

  int update(int idx, int newval) {
    return update(idx, newval, 1, 0, len - 1);
  }

  SegTree(vector<int>& arr) {
    len = arr.size();
    tree.resize(len * 4);
    init_tree(arr, 0, len - 1, 1);
  }
};

int main() {
  int N;
  vector<int> arr;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int n;
    scanf("%d", &n);
    arr.push_back(n);
  }
  SegTree st(arr);
  int M;
  scanf("%d", &M);
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == 1) st.update(b - 1, c);
    else if (a == 2) printf("%d\n", c - b + 1 - st.query(b - 1, c - 1));
    else printf("%d\n", st.query(b - 1, c - 1));
  }
  return 0;
}
