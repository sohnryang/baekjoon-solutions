/*
 * Baekjoon Online Judge #18407
 * https://www.acmicpc.net/problem/18407
 */

#include <algorithm>
#include <cstdio>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

class RangeMax {
 private:
  vector<long long> tree;
  vector<long long> lazy;
  int len;

  void update_lazy(int node, int lo, int hi) {
    if (lazy[node] == 0) return;
    tree[node] = lazy[node];
    if (lo != hi) {
      lazy[node * 2] = lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = 0;
  }

  long long query(int lo, int hi, int node, int node_lo, int node_hi) {
    update_lazy(node, node_lo, node_hi);
    if (hi < node_lo || node_hi < lo) return numeric_limits<long long>::min();
    if (lo <= node_lo && node_hi <= hi) return tree[node];
    int mid = (node_lo + node_hi) / 2;
    return max(query(lo, hi, node * 2, node_lo, mid),
               query(lo, hi, node * 2 + 1, mid + 1, node_hi));
  }

  void update_range(int lo, int hi, long long new_value, int node, int node_lo,
                    int node_hi) {
    update_lazy(node, node_lo, node_hi);
    if (hi < node_lo || lo > node_hi) return;
    if (lo <= node_lo && node_hi <= hi) {
      tree[node] = new_value;
      if (node_lo != node_hi) {
        lazy[node * 2] = new_value;
        lazy[node * 2 + 1] = new_value;
      }
      return;
    }
    int mid = (node_lo + node_hi) / 2;
    update_range(lo, hi, new_value, node * 2, node_lo, mid);
    update_range(lo, hi, new_value, node * 2 + 1, mid + 1, node_hi);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
  }

 public:
  long long query(int lo, int hi) { return query(lo, hi, 1, 0, len - 1); }

  void update_range(int lo, int hi, long long new_value) {
    update_range(lo, hi, new_value, 1, 0, len - 1);
  }

  RangeMax(int _len) {
    len = _len;
    tree.resize(len * 4);
    lazy.resize(len * 4);
  }
};

int N;
vector<pair<int, int>> blocks;
vector<int> range_start;
vector<int> range_end;
vector<int> indicies;

int index(int x) {
  return lower_bound(indicies.begin(), indicies.end(), x) - indicies.begin();
}

int main() {
  scanf("%d", &N);
  RangeMax st(N * 2);
  indicies.resize(N * 2);
  for (int i = 0; i < N; ++i) {
    int W, D;
    scanf("%d %d", &W, &D);
    D--;
    blocks.push_back({D, W + D - 1});
    indicies[i * 2] = D;
    indicies[i * 2 + 1] = W + D - 1;
  }
  sort(indicies.begin(), indicies.end());

  for (auto block : blocks) {
    int lo = index(block.first), hi = index(block.second);
    long long maxval = st.query(lo, hi);
    st.update_range(lo, hi, maxval + 1);
  }
  printf("%lld\n", st.query(0, 2 * N - 1));
  return 0;
}
