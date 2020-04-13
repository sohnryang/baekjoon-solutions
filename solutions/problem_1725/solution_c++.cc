/*
 * Baekjoon Online Judge #1725
 * https://www.acmicpc.net/problem/1725
 */

#include <algorithm>
#include <cstdio>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

typedef pair<long long, int> ktype;
class RMQ {
 private:
  vector<ktype> tree;
  int len;

  ktype init_tree(vector<ktype>& arr, int lo, int hi, int node) {
    if (lo == hi) return tree[node] = arr[lo];
    int mid = (lo + hi) / 2;
    ktype left = init_tree(arr, lo, mid, node * 2);
    ktype right = init_tree(arr, mid + 1, hi, node * 2 + 1);
    return tree[node] = min(left, right);
  }

  ktype query(int lo, int hi, int node, int node_lo, int node_hi) {
    if (hi < node_lo || node_hi < lo)
      return {numeric_limits<long long>::max(), -1};
    if (lo <= node_lo && node_hi <= hi) return tree[node];
    int mid = (node_lo + node_hi) / 2;
    return min(query(lo, hi, node * 2, node_lo, mid),
               query(lo, hi, node * 2 + 1, mid + 1, node_hi));
  }

  ktype update(int idx, ktype newval, int node, int node_lo, int node_hi) {
    if (idx < node_lo || node_hi < idx) return tree[node];
    if (node_lo == node_hi) return tree[node] = newval;
    int mid = (node_lo + node_hi) / 2;
    return tree[node] =
               min(update(idx, newval, node * 2, node_lo, mid),
                   update(idx, newval, node * 2 + 1, mid + 1, node_hi));
  }

 public:
  ktype query(int lo, int hi) { return query(lo, hi, 1, 0, len - 1); }

  ktype update(int idx, ktype newval) {
    return update(idx, newval, 1, 0, len - 1);
  }

  RMQ(vector<ktype>& arr) {
    len = arr.size();
    tree.resize(len * 4);
    init_tree(arr, 0, len - 1, 1);
  }
};

int N;
vector<ktype> arr;

long long solve(RMQ& rmq, int lo, int hi) {
  if (lo > hi) return -1;
  if (lo < 0 || hi >= N) return -1;
  if (lo == hi) return arr[lo].first;
  int smallest = rmq.query(lo, hi).second;
  long long height = arr[smallest].first;
  return max(solve(rmq, lo, smallest - 1),
             max(solve(rmq, smallest + 1, hi), (hi - lo + 1) * height));
}

int main() {
  scanf("%d", &N);
  arr.clear();
  for (int i = 0; i < N; ++i) {
    int X;
    scanf("%d", &X);
    arr.push_back({(long long)X, i});
  }
  RMQ rmq(arr);
  printf("%lld\n", solve(rmq, 0, N - 1));
  return 0;
}
