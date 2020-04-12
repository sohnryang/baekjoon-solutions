/*
 * Baekjoon Online Judge #1572
 * https://www.acmicpc.net/problem/1572
 */

#include <cmath>
#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

class RangeSum {
 private:
  vector<long long> tree;
  int len, tree_size;

  long long update(int idx, int delta, int node, int node_lo, int node_hi) {
    if (idx < node_lo || node_hi < idx) return tree[node];
    if (node_lo == node_hi) return tree[node] += delta;
    int mid = (node_lo + node_hi) / 2;
    return tree[node] = update(idx, delta, node * 2, node_lo, mid) +
                        update(idx, delta, node * 2 + 1, mid + 1, node_hi);
  }

  int query(int node, int node_lo, int node_hi, int kth) {
    if (node_lo == node_hi) return node_lo;
    int mid = (node_lo + node_hi) / 2;
    if (node * 2 <= tree_size && kth <= tree[node * 2])
      return query(node * 2, node_lo, mid, kth);
    else
      return query(node * 2 + 1, mid + 1, node_hi, kth - tree[node * 2]);
  }

 public:
  int query(int kth) {
    return query(1, 0, len - 1, kth);
  }
 
  long long update(int idx, int delta) {
    return update(idx, delta, 1, 0, len - 1);
  }

  RangeSum(int _len) {
    len = _len;
    tree.resize(len * 4);
    int height = ceil(log2(1e6));
    tree_size = 1 << (height + 1);
  }
};

const int MAX_X = 65536;
int N, K;
int main() {
  scanf("%d %d", &N, &K);
  RangeSum rsum(MAX_X + 1);
  deque<int> dq;
  int current_nodes = 0;
  long long result = 0;
  for (int i = 0; i < N; ++i) {
    int X;
    scanf("%d", &X);
    dq.push_front(X);
    if (current_nodes >= K) {
      int oldest = dq.back();
      dq.pop_back();
      rsum.update(oldest, -1);
      current_nodes--;
    }
    rsum.update(X, 1);
    current_nodes++;
    if (current_nodes != K) continue;
    int median = rsum.query((K + 1) / 2);
    result += median;
  }
  printf("%lld\n", result);
  return 0;
}
