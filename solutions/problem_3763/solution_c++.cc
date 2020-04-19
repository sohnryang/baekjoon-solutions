/*
 * Baekjoon Online Judge #3763
 * https://www.acmicpc.net/problem/3763
 */

#include <ios>
#include <iostream>

using namespace std;

struct column_object {
  column_object* left;
  column_object* right;
  column_object* up;
  column_object* down;
  column_object* column_top;
  int size;
  string name;
};

const int SIZE = 16, BOX_SIZE = 4;
string raw_sudoku[SIZE];
int sudoku[SIZE][SIZE];

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < SIZE; ++i) cin >> raw_sudoku[i];
  return 0;
}
