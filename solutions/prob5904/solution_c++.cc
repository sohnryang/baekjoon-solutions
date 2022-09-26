/*
 * Baekjoon Online Judge #5904
 * https://www.acmicpc.net/problem/5904
 */

#include <ios>
#include <iostream>

using namespace std;

const int start_len = 1073741792;

char moo(int n, int k, int l) {
  if (k == 0)
    return n == 1 ? 'm' : 'o';
  int next_l = (l - k - 3) / 2;
  if (next_l < n && n <= l - next_l)
    return n - next_l == 1 ? 'm' : 'o';
  else if (n <= next_l)
    return moo(n, k - 1, next_l);
  else
    return moo(n - (l - next_l), k - 1, next_l);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  cout << moo(N, 27, start_len) << "\n";

  return 0;
}
