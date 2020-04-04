/*
 * Baekjoon Online Judge #18378
 * https://www.acmicpc.net/problem/18378
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

class RangeSum {
 private:
  vector<int> tree;
  vector<int> lazy;
  int len;

  void update_lazy(int node, int lo, int hi) {
    if (lazy[node] == -1) return;
    if (lazy[node] == 1) tree[node] = (hi - lo + 1);
    else tree[node] = 0;
    if (lo != hi) {
      lazy[node * 2] = lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = -1;
  }

  int query(int lo, int hi, int node, int node_lo, int node_hi) {
    update_lazy(node, node_lo, node_hi);
    if (hi < node_lo || node_hi < lo) return 0;
    if (lo <= node_lo && node_hi <= hi) return tree[node];
    int mid = (node_lo + node_hi) / 2;
    return query(lo, hi, node * 2, node_lo, mid) +
           query(lo, hi, node * 2 + 1, mid + 1, node_hi);
  }

  void update_range(int lo, int hi, int delta, int node, int node_lo,
                    int node_hi) {
    update_lazy(node, node_lo, node_hi);
    if (hi < node_lo || lo > node_hi) return;
    if (lo <= node_lo && node_hi <= hi) {
      if (delta == 1) tree[node] = (node_hi - node_lo + 1);
      else tree[node] = 0;
      if (node_lo != node_hi) {
        lazy[node * 2] = delta;
        lazy[node * 2 + 1] = delta;
      }
      return;
    }
    int mid = (node_lo + node_hi) / 2;
    update_range(lo, hi, delta, node * 2, node_lo, mid);
    update_range(lo, hi, delta, node * 2 + 1, mid + 1, node_hi);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }

 public:
  int query(int lo, int hi) { return query(lo, hi, 1, 0, len - 1); }

  void update_range(int lo, int hi, int delta) {
    update_range(lo, hi, delta, 1, 0, len - 1);
  }

  RangeSum(int _len) {
    len = _len;
    tree.resize(len * 4);
    lazy.assign(len * 4, -1);
  }
};

const int MAX_N = 100'000;
int N, M, current_index = 0;
bool visited[MAX_N + 1];
vector<int> arr;
vector<int> tree[MAX_N + 1];
vector<int> range_start;
vector<int> range_end;

void dfs(int start) {
  visited[start] = true;
  range_start[start] = ++current_index;
  for (int child: tree[start])
    if (!visited[child])
      dfs(child);
  range_end[start] = current_index;
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    int n;
    scanf("%d", &n);
    tree[n].push_back(i);
  }
  memset(visited, false, sizeof(visited));
  range_start.assign(N + 1, -1);
  range_end.assign(N + 1, -1);
  dfs(1);

#ifdef DEBUG
  for (int elem: range_start) printf("%d ", elem);
  printf("\n");
  for (int elem: range_end) printf("%d ", elem);
  printf("\n");
#endif

  RangeSum st(N + 1);
  st.update_range(0, N, 1);
  scanf("%d", &M);
  for (int i = 0; i < M; ++i) {
    int p, q;
    scanf("%d %d", &p, &q);
    if (p == 1) {
      st.update_range(range_start[q] + 1, range_end[q], 1);
    } else if (p == 2) {
      st.update_range(range_start[q] + 1, range_end[q], 0);
    } else {
      printf("%d\n", st.query(range_start[q] + 1, range_end[q]));
    }
  }
  return 0;
}
