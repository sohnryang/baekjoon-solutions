/*
 * Baekjoon Online Judge #3763
 * https://www.acmicpc.net/problem/3763
 */

#include <ios>
#include <iostream>
#include <string>

using namespace std;

string raw_sudoku[16];
int sudoku[16][16];

struct column_object {
  column_object* left;
  column_object* right;
  column_object* up;
  column_object* down;
  column_object* column_top;
};

const int SUDOKU_SIZE = 16, MATRIX_COLS = 16 * 16 * 16;
column_object master;
column_object matrix[MATRIX_COLS];

inline int get_box_position(int row, int col) {
  return (row / BOX_SIZE) * BOX_SIZE + col / BOX_SIZE;
}

void process_board() {
  for (int i = 0; i < SUDOKU_SIZE; ++i) {
    for (int j = 0; j < SUDOKU_SIZE; ++j) {
      if (raw_sudoku[i][j] == '-')
        sudoku[i][j] = 0;
      else
        sudoku[i][j] = raw_sudoku[i][j] - 'A' + 1;
    }
  }
}

void construct_matrix() {
  master.right = &matrix[0];
  matrix[0].left = &master;
  master.left = &matrix[SUDOKU_SIZE - 1];
  matrix[SUDOKU_SIZE - 1].right = &master;
  for (int i = 1; i < MATRIX_COLS; ++i) {
    matrix[i].left = &matrix[i - 1];
    matrix[i - 1].right = &matrix[i];
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < SUDOKU_SIZE; ++i) cin >> raw_sudoku[i];
  process_board();
  construct_matrix();
  return 0;
}
