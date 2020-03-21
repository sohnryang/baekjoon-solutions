/*
 * Baekjoon Online Judge #1074
 * https://www.acmicpc.net/problem/1074
 */

#include <cmath>
#include <cstdio>

using namespace std;

int N, R, C;

int array_traverse(int n, int r, int c) {
  if (n == 0) return 0;
  int half_len = pow(2, n - 1);
  int half_size = half_len * half_len;
  if (r < half_len && c < half_len)
    return array_traverse(n - 1, r, c);
  else if (r < half_len && c >= half_len)
    return array_traverse(n - 1, r, c - half_len) + half_size;
  else if (r >= half_len && c < half_len)
    return array_traverse(n - 1, r - half_len, c) + half_size * 2;
  else
    return array_traverse(n - 1, r - half_len, c - half_len) + half_size * 3;
}

int main() {
  scanf("%d %d %d", &N, &R, &C);
  printf("%d\n", array_traverse(N, R, C));
  return 0;
}
