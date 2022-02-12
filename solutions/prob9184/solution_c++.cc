/*
 * Baekjoon Online Judge #9184
 * https://www.acmicpc.net/problem/9184
 */

#include <ios>
#include <iostream>

using namespace std;

int A, B, C, dp[21][21][21];
bool visited[21][21][21];

int w(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0)
    return 1;
  else if (a > 20 || b > 20 || c > 20)
    return w(20, 20, 20);
  int &res = dp[a][b][c];
  bool &v = visited[a][b][c];
  if (v)
    return res;
  if (a < b && b < c)
    res = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
  else
    res = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) -
          w(a - 1, b - 1, c - 1);
  v = true;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    cin >> A >> B >> C;
    if (A == -1 && B == -1 && C == -1)
      break;
    cout << "w(" << A << ", " << B << ", " << C << ") = ";
    cout << w(A, B, C) << "\n";
  }

  return 0;
}
