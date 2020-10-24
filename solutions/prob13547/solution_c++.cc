/*
 * Baekjoon Online Judge #13547
 * https://www.acmicpc.net/problem/13547
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

const int MAX_A = 1000000;
int N, M, block_size, current_result = 0;
vector<int> A, counts, answers;

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
  if (adding) {
    if (counts[A[idx]]++ == 0) current_result++;
  } else {
    if (--counts[A[idx]] == 0) current_result--;
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
