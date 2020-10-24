/*
 * Baekjoon Online Judge #18870
 * https://www.acmicpc.net/problem/18870
 */

#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  vector<int> X(N);
  for (int i = 0; i < N; ++i) scanf("%d", &X[i]);
  vector<int> sorted = X;
  sort(sorted.begin(), sorted.end());
  sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
  for (int x : X)
    printf("%ld ",
           lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin());
  printf("\n");
  return 0;
}
