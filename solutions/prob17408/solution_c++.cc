/*
 * Baekjoon Online Judge #17408
 * https://www.acmicpc.net/problem/17408
 */

#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <cstdio>

using namespace std;

int N, M;
typedef pair<long long, int> p_li;
vector<p_li> A;

class RMQ {
 private:
  vector<p_li> tree;
  int len;

  p_li init_tree(vector<p_li>& arr, int lo, int hi, int node) {
    if (lo == hi) return tree[node] = arr[lo];
    int mid = (lo + hi) / 2;
    auto left = init_tree(arr, lo, mid, node * 2);
    auto right = init_tree(arr, mid + 1, hi, node * 2 + 1);
    return tree[node] = min(left, right);
  }

  p_li query(int lo, int hi, int node, int node_lo, int node_hi) {
    if (hi < node_lo || node_hi < lo) return {numeric_limits<long long>::max(), -1};
    if (lo <= node_lo && node_hi <= hi) return tree[node];
    int mid = (node_lo + node_hi) / 2;
    return min(query(lo, hi, node * 2, node_lo, mid),
               query(lo, hi, node * 2 + 1, mid + 1, node_hi));
  }

  p_li update(int idx, p_li newval, int node, int node_lo, int node_hi) {
    if (idx < node_lo || node_hi < idx) return tree[node];
    if (node_lo == node_hi) return tree[node] = newval;
    int mid = (node_lo + node_hi) / 2;
    return tree[node] =
               min(update(idx, newval, node * 2, node_lo, mid),
                   update(idx, newval, node * 2 + 1, mid + 1, node_hi));
  }

 public:
  p_li query(int lo, int hi) { return query(lo, hi, 1, 0, len - 1); }

  p_li update(int idx, p_li newval) {
    return update(idx, newval, 1, 0, len - 1);
  }

  RMQ(vector<p_li>& arr) {
    len = arr.size();
    tree.resize(len * 4);
    init_tree(arr, 0, len - 1, 1);
  }
};

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int n;
    scanf("%d", &n);
    A.push_back({-n, i});
  }
  RMQ rmq(A);
  scanf("%d", &M);
  for (int i = 0; i < M; ++i) {
    int c;
    scanf("%d", &c);
    if (c == 1) {
      int idx, v;
      scanf("%d %d", &idx, &v);
      rmq.update(idx - 1, {-v, idx - 1});
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      auto largest_elem = rmq.query(l - 1, r - 1);
      auto largest = -largest_elem.first;
      auto largest_pos = largest_elem.second;
      rmq.update(largest_pos, {numeric_limits<long long>::max(), largest_pos});
      auto seclargest_elem = rmq.query(l - 1, r - 1);
      auto seclargest = -seclargest_elem.first;
      rmq.update(largest_pos, {-largest, largest_pos});
      printf("%lld\n", largest + seclargest);
    }
  }
  return 0;
}
