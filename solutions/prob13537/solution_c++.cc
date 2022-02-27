/*
 * Baekjoon Online Judge #13537
 * https://www.acmicpc.net/problem/13537
 */

#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> A;
vector<vector<int>> tree;

const vector<int> &init_tree(int lo, int hi, int node) {
  if (lo == hi)
    return tree[node] = {A[lo]};
  int mid = (lo + hi) / 2;
  auto left = init_tree(lo, mid, 2 * node);
  auto right = init_tree(mid + 1, hi, 2 * node + 1);
  auto left_it = left.begin();
  auto right_it = right.begin();
  while (left_it != left.end() || right_it != right.end()) {
    if (left_it == left.end())
      tree[node].push_back(*(right_it++));
    else if (right_it == right.end())
      tree[node].push_back(*(left_it++));
    else if (*left_it < *right_it)
      tree[node].push_back(*(left_it++));
    else
      tree[node].push_back(*(right_it++));
  }
  return tree[node];
}

int query(int lo, int hi, int node, int node_lo, int node_hi, int k) {
  if (hi < node_lo || node_hi < lo)
    return 0;
  if (lo <= node_lo && node_hi <= hi)
    return tree[node].end() -
           upper_bound(tree[node].begin(), tree[node].end(), k);
  int mid = (node_lo + node_hi) / 2;
  return query(lo, hi, 2 * node, node_lo, mid, k) +
         query(lo, hi, 2 * node + 1, mid + 1, node_hi, k);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  A.resize(N);
  for (int &a : A)
    cin >> a;

  tree.resize(4 * N);
  init_tree(0, N - 1, 1);
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int I, J, K;
    cin >> I >> J >> K;
    cout << query(I - 1, J - 1, 1, 0, N - 1, K) << "\n";
  }

  return 0;
}
