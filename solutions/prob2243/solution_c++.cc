/*
 * Baekjoon Online Judge #2243
 * https://www.acmicpc.net/problem/2243
 */

#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

class RangeSum {
 private:
  vector<long long> tree;
  int len, tree_size;

  long long update(int idx, int newval, int node, int node_lo, int node_hi) {
    if (idx < node_lo || node_hi < idx) return tree[node];
    if (node_lo == node_hi) return tree[node] += newval;
    int mid = (node_lo + node_hi) / 2;
    return tree[node] = update(idx, newval, node * 2, node_lo, mid) +
                        update(idx, newval, node * 2 + 1, mid + 1, node_hi);
  }

 public:
  int query(int node, int node_lo, int node_hi, int kth) {
    if (node_lo == node_hi) return node_lo;
    int mid = (node_lo + node_hi) / 2;
    if (node * 2 <= tree_size && kth <= tree[node * 2])
      return query(node * 2, node_lo, mid, kth);
    else
      return query(node * 2 + 1, mid + 1, node_hi, kth - tree[node * 2]);
  }

  long long update(int idx, int newval) {
    return update(idx, newval, 1, 0, len - 1);
  }

  RangeSum(int _len) {
    len = _len;
    tree.resize(len * 4);
    int height = ceil(log2(1e6));
    tree_size = 1 << (height + 1);
  }
};

int N;
int main() {
  scanf("%d", &N);
  RangeSum rsum(1e6 + 1);
  for (int i = 0; i < N; ++i) {
    int A, B;
    scanf("%d %d", &A, &B);
    if (A == 1) {
      int result = rsum.query(1, 0, 1e6, B);
      printf("%d\n", result);
      rsum.update(result, -1);
    } else {
      int C;
      scanf("%d", &C);
      rsum.update(B, C);
    }
  }
  return 0;
}
