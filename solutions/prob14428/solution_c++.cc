/*
 * Baekjoon Online Judge #14428
 * https://www.acmicpc.net/problem/14428
 */

#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <cstdio>

using namespace std;

typedef pair<long long, int> elem_type;

class RMQ {
 private:
  vector<elem_type> tree;
  int len;

  elem_type init_tree(vector<elem_type>& arr, int lo, int hi, int node) {
    if (lo == hi) return tree[node] = arr[lo];
    int mid = (lo + hi) / 2;
    auto left = init_tree(arr, lo, mid, node * 2);
    auto right = init_tree(arr, mid + 1, hi, node * 2 + 1);
    return tree[node] = min(left, right);
  }

  elem_type query(int lo, int hi, int node, int node_lo, int node_hi) {
    if (hi < node_lo || node_hi < lo) return {numeric_limits<long long>::max(), -1};
    if (lo <= node_lo && node_hi <= hi) return tree[node];
    int mid = (node_lo + node_hi) / 2;
    return min(query(lo, hi, node * 2, node_lo, mid),
               query(lo, hi, node * 2 + 1, mid + 1, node_hi));
  }

  elem_type update(int idx, elem_type newval, int node, int node_lo, int node_hi) {
    if (idx < node_lo || node_hi < idx) return tree[node];
    if (node_lo == node_hi) return tree[node] = newval;
    int mid = (node_lo + node_hi) / 2;
    return tree[node] =
               min(update(idx, newval, node * 2, node_lo, mid),
                   update(idx, newval, node * 2 + 1, mid + 1, node_hi));
  }

 public:
  elem_type query(int lo, int hi) { return query(lo, hi, 1, 0, len - 1); }

  elem_type update(int idx, elem_type newval) {
    return update(idx, newval, 1, 0, len - 1);
  }

  RMQ(vector<elem_type>& arr) {
    len = arr.size();
    tree.resize(len * 4);
    init_tree(arr, 0, len - 1, 1);
  }
};

int main() {
  int N;
  scanf("%d", &N);
  vector<elem_type> arr;
  for (int i = 0; i < N; ++i) {
    long long n;
    scanf("%lld", &n);
    arr.push_back({n, i});
  }
  RMQ rmq(arr);
  int M;
  scanf("%d", &M);
  for (int i = 0; i < M; ++i) {
    int cmd;
    scanf("%d", &cmd);
    if (cmd == 1) {
      int idx, v;
      scanf("%d %d", &idx, &v);
      rmq.update(idx - 1, {v, idx - 1});
    } else {
      int s, e;
      scanf("%d %d", &s, &e);
      printf("%d\n", rmq.query(s - 1, e - 1).second + 1);
    }
  }
  return 0;
}
