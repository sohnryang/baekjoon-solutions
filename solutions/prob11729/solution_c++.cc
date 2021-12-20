/*
 * Baekjoon Online Judge #11729
 * https://www.acmicpc.net/problem/11729
 */

#include <cmath>
#include <ios>
#include <iostream>

using namespace std;

int N;

void move_tower(int disks, int src, int tmp, int dest) {
  if (disks == 1) {
    cout << src << " " << dest << "\n";
    return;
  }
  move_tower(disks - 1, src, dest, tmp);
  cout << src << " " << dest << "\n";
  move_tower(disks - 1, tmp, src, dest);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  cout << (1 << N) - 1 << "\n";
  move_tower(N, 1, 2, 3);

  return 0;
}
