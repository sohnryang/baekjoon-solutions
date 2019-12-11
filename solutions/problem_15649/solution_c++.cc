/*
 * Baekjoon Online Judge #15649
 * https://www.acmicpc.net/problem/15649
 */

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int N, M;

void print_seq(int n, const vector<int>& picked) {
  if (n == 0)
    for (int i = 0; i < M; ++i)
      printf("%d%c", picked[i] + 1, i + 1 == M ? '\n' : ' ');
  else {
    for (int i = 0; i < N; ++i) {
      if (count(picked.begin(), picked.end(), i) == 1) continue;
      vector<int> pick = picked;
      pick.push_back(i);
      print_seq(n - 1, pick);
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  print_seq(M, {});
  return 0;
}
