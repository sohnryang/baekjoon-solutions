/*
 * Baekjoon Online Judge #17353
 * https://www.acmicpc.net/problem/17353
 */

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct RangeInfo {
  long long value, update_count;
};

class RangeSum {
 private:
  vector<RangeInfo> tree;
  int len;

  void init_tree(vector<long long>& arr, int lo, int hi, int node) {
    if (lo == hi)
      tree[node].value = arr[lo];
    else {
      int mid = (lo + hi) / 2;
      init_tree(arr, lo, mid, node * 2);
      init_tree(arr, mid + 1, hi, node * 2 + 1);
    }
  }

  long long query(int index, int node, int node_lo, int node_hi) {
    if (index < node_lo || node_hi < index) return 0;
    if (node_lo == node_hi) return tree[node].value;
    int mid = (node_lo + node_hi) / 2;
    return query(index, node * 2, node_lo, mid) +
           query(index, node * 2 + 1, mid + 1, node_hi) + tree[node].value +
           tree[node].update_count * (index - node_lo);
  }

  void update(int lo, int hi, int node, int node_lo, int node_hi) {
    if (hi < node_lo || lo > node_hi) return;
    if (lo <= node_lo && node_hi <= hi) {
      tree[node].value += node_lo - lo + 1;
      tree[node].update_count++;
      return;
    }
    int mid = (node_lo + node_hi) / 2;
    update(lo, hi, node * 2, node_lo, mid);
    update(lo, hi, node * 2 + 1, mid + 1, node_hi);
  }

 public:
  long long query(int index) { return query(index, 1, 0, len - 1); }

  void update(int lo, int hi) { update(lo, hi, 1, 0, len - 1); }

  RangeSum(vector<long long>& arr) {
    len = arr.size();
    tree.resize(len * 4);
    init_tree(arr, 0, len - 1, 1);
  }
};

int N, Q;
int main() {
  scanf("%d", &N);
  vector<long long> arr;
  for (int i = 0; i < N; ++i) {
    int n;
    scanf("%d", &n);
    arr.push_back(n);
  }
  RangeSum rsum(arr);
  scanf("%d", &Q);
  for (int i = 0; i < Q; ++i) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int L, R;
      scanf("%d %d", &L, &R);
      L--;
      R--;
      rsum.update(L, R);
    } else {
      int X;
      scanf("%d", &X);
      X--;
      printf("%lld\n", rsum.query(X));
    }
  }
  return 0;
}
