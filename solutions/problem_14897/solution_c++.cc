/*
 * Baekjoon Online Judge #14897
 * https://www.acmicpc.net/problem/14897
 */

#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000000;
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

void calc(const vector<int>& arr, int idx, bool adding) {
  if (adding) {
    if (counts[arr[idx]]++ == 0) current_result++;
  } else {
    if (--counts[arr[idx]] == 0) current_result--;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int X;
    cin >> X;
    A.push_back(X);
  }
  vector<int> sorted = A;
  sort(sorted.begin(), sorted.end());
  sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
  vector<int> compressed;
  for (int x : A)
    compressed.push_back(lower_bound(sorted.begin(), sorted.end(), x) -
                         sorted.begin());

#ifdef DEBUG
  for (int x : compressed) cout << x << ' ';
  cout << '\n';
#endif

  block_size = (int)sqrt(N);
  counts.resize(MAX_N + 1);

  cin >> M;
  answers.resize(M);
  for (int i = 0; i < M; ++i) {
    int L, R;
    cin >> L >> R;
    query q(L - 1, R - 1, i);
    Q.push_back(q);
  }
  sort(Q.begin(), Q.end());

  int lo = 1, hi = 0;
  for (int i = 0; i < M; ++i) {
    while (Q[i].lo < lo) calc(compressed, --lo, true);
    while (Q[i].lo > lo) calc(compressed, lo++, false);
    while (Q[i].hi < hi) calc(compressed, hi--, false);
    while (Q[i].hi > hi) calc(compressed, ++hi, true);
    answers[Q[i].id] = current_result;
  }

  for (int a : answers) cout << a << '\n';
  return 0;
}
