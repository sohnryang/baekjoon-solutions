/*
 * Baekjoon Online Judge #3763
 * https://www.acmicpc.net/problem/3763
 */

#include <ios>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

struct column_object {
  column_object* left;
  column_object* right;
  column_object* up;
  column_object* down;
  column_object* column_top;
  int size;
  tuple<int, int, int> name;
};

const int SIZE = 16, BOX_SIZE = 4;
string raw_sudoku[SIZE];
int sudoku[SIZE][SIZE];
column_object* master;
vector<column_object*> headers;

void process_sudoku() {
  for (int i = 0; i < SIZE; ++i)
    for (int j = 0; j < SIZE; ++j) {
      char c = raw_sudoku[i][j];
      sudoku[i][j] = c == '-' ? 0 : c - 'A' + 1;
    }
}

void construct_headers() {
  master = new column_object();
  master->up = master;
  master->down = master;

  column_object* prev_col = master;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      for (int k = 0; k < SIZE; ++k) {
        column_object* col = new column_object();
        col->left = prev_col;
        prev_col->right = col;
        col->up = col;
        col->down = col;
        col->name = {i, j, k};
        headers.push_back(col);
        prev_col = col;
      }
    }
  }
  master->left = prev_col;
  prev_col->right = master;
}

void construct_matrix() { construct_headers(); }

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < SIZE; ++i) cin >> raw_sudoku[i];
  process_sudoku();
  construct_matrix();
  return 0;
}
