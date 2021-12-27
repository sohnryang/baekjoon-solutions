/*
 * Baekjoon Online Judge #11092
 * https://www.acmicpc.net/problem/11092
 */

#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 15;
int N;
vector<int> A;

int cross(int lo, int hi) {
  int len = hi - lo;
  if (len > 3)
    return A[lo] + A[hi - 1] + min(2 * A[lo + 1], A[lo] + A[hi - 2]) +
           cross(lo, hi - 2);
  else if (len == 3)
    return A[lo] + A[lo + 1] + A[lo + 2];
  return A[lo + 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  A.assign(N, 0);
  for (int i = 0; i < N; ++i)
    cin >> A[i];
  sort(A.begin(), A.end());
  cout << cross(0, N) << "\n";

  return 0;
}
