/*
 * Baekjoon Online Judge #2740
 * https://www.acmicpc.net/problem/2740
 */

#include <ios>
#include <iostream>

using namespace std;

const int MAX_SIZE = 101;
int N, M, K, A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE],
    C[MAX_SIZE][MAX_SIZE];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> M;
  for (int y = 0; y < N; ++y)
    for (int x = 0; x < M; ++x) cin >> A[y][x];
  cin >> M >> K;
  for (int y = 0; y < M; ++y)
    for (int x = 0; x < K; ++x) cin >> B[y][x];
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < K; ++j)
      for (int k = 0; k < M; ++k) C[i][j] += A[i][k] * B[k][j];
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < K; ++x) cout << C[y][x] << " ";
    cout << '\n';
  }
  return 0;
}
