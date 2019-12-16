/*
 * Baekjoon Online Judge #13548
 * https://www.acmicpc.net/problem/13548
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

const int MAX_A = 1000000, MAX_N = 100000;
int N, M, block_size, current_result = 0;
vector<int> A, counts, answers, table;

struct query {
  int lo, hi, id;

  query(int _lo, int _hi, int _id) {
    lo = _lo;
    hi = _hi;
    id = _id;
  }

  bool operator<(const query& q) const {
    int x = hi / block_size;
    int y = q.hi / block_size;
    return x == y ? lo < q.lo : x < y;
  }
};
vector<query> Q;

void calc(int idx, bool adding) {
  int elem = A[idx];
  if (adding) {
    if (counts[elem] != 0) table[counts[elem]]--;
    counts[elem]++;
    table[counts[elem]]++;
    current_result = max(current_result, counts[elem]);
  } else {
    table[counts[elem]]--;
    if (counts[elem] == current_result && !table[counts[elem]])
      current_result--;
    counts[elem]--;
    table[counts[elem]]++;
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int n;
    scanf("%d", &n);
    A.push_back(n);
  }
  block_size = (int)sqrt(N);
  counts.resize(MAX_A + 1);
  table.resize(MAX_N + 1);

  scanf("%d", &M);
  answers.resize(M);
  for (int i = 0; i < M; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    query q(l - 1, r - 1, i);
    Q.push_back(q);
  }
  sort(Q.begin(), Q.end());

  int lo = 1, hi = 0;
  for (int i = 0; i < M; ++i) {
    while (Q[i].lo < lo) calc(--lo, true);
    while (Q[i].lo > lo) calc(lo++, false);
    while (Q[i].hi < hi) calc(hi--, false);
    while (Q[i].hi > hi) calc(++hi, true);
    answers[Q[i].id] = current_result;
  }

  for (int a : answers) printf("%d\n", a);
  return 0;
}
