/*
 * Baekjoon Online Judge #15652
 * https://www.acmicpc.net/problem/15652
 */

#include <ios>
#include <iostream>

using namespace std;

int N, M, idx[9];

void pick(int i, int l) {
  for (idx[i] = l; idx[i] <= N; ++idx[i]) {
    if (i == M - 1) {
      for (int j = 0; j < M; ++j)
        cout << idx[j] << " ";
      cout << "\n";
    } else
      pick(i + 1, idx[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  pick(0, 1);
  return 0;
}
