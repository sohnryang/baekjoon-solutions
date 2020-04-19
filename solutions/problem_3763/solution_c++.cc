/*
 * Baekjoon Online Judge #3763
 * https://www.acmicpc.net/problem/3763
 */

#include <ios>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

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
bool row_filled[SIZE][SIZE], col_filled[SIZE][SIZE], box_filled[SIZE][SIZE];

column_object* master;
vector<column_object*> matrix;
vector<string> solution, current;

inline int box_pos(int row, int col) {
  return (row / BOX_SIZE) * BOX_SIZE + col / BOX_SIZE;
}

column_object* header(string name) {
  column_object* header = new column_object();
  header->up = header;
  header->down = header;
  header->name = name;
  header->size = 0;
  return header;
}

column_object* cell(string col_name) {
  column_object* cell = new column_object();
  column_object* col = matrix[0];
  while (col->name != col_name) col = col->right;
  col->size++;
  cell->down = col;
  cell->up = col->up;
  cell->down->up = cell;
  cell->up->down = cell;
  cell->column_top = col;
  return cell;
}

void process_board() {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      if (raw_sudoku[i][j] == '-')
        sudoku[i][j] = 0;
      else {
        int value = raw_sudoku[i][j] - 'A' + 1;
        sudoku[i][j] = value;
        row_filled[i][value] = true;
        col_filled[j][value] = true;
        box_filled[box_pos(i, j)][value] = true;
      }
    }
  }
}

void construct_matrix() {
  matrix.push_back(header("master"));
  for (int i = 0; i < SIZE; ++i)
    for (int j = 0; j < SIZE; ++j)
      if (sudoku[i][j] == 0)
        matrix.push_back(header(string("p") + to_string(i) + to_string(j)));
  for (int i = 0; i < SIZE; ++i)
    for (int k = 0; k < SIZE; ++k) {
      if (!row_filled[i][k])
        matrix.push_back(header(string("r") + to_string(i) + to_string(k)));
      if (!col_filled[i][k])
        matrix.push_back(header(string("c") + to_string(i) + to_string(k)));
      if (!box_filled[i][k])
        matrix.push_back(header(string("g") + to_string(i) + to_string(k)));
    }
  for (int i = 1; i < matrix.size(); ++i) {
    matrix[i]->left = matrix[i - 1];
    matrix[i - 1]->right = matrix[i];
  }
  matrix[0]->left = matrix[matrix.size() - 1];
  matrix[matrix.size() - 1]->right = matrix[0];
  master = matrix[0];

  for (int i = 0; i < SIZE; ++i)
    for (int j = 0; j < SIZE; ++j)
      for (int k = 0; k < SIZE; ++k)
        if (!row_filled[i][k] && !col_filled[j][k] &&
            !box_filled[box_pos(i, j)][k]) {
          matrix.push_back(cell(string("p") + to_string(i) + to_string(j)));
          matrix.push_back(cell(string("r") + to_string(i) + to_string(k)));
          matrix.push_back(cell(string("c") + to_string(j) + to_string(k)));
          matrix.push_back(
              cell(string("b") + to_string(box_pos(i, j)) + to_string(k)));
        }

  for (int i = 0; i < matrix.size(); i += 4) {
    matrix[i]->right = matrix[i + 1];
    matrix[i + 1]->right = matrix[i + 2];
    matrix[i + 2]->right = matrix[i + 3];
    matrix[i + 3]->right = matrix[i];
    matrix[i]->left = matrix[i + 3];
    matrix[i + 1]->left = matrix[i];
    matrix[i + 2]->left = matrix[i + 1];
    matrix[i + 3]->left = matrix[i + 2];
  }
}

string copy_current() {
  string solution;
  for (string& piece : current) solution += piece;
  return solution;
}

column_object* smallest_column() {
  column_object* h = master->right;
  column_object* col = h;
  int size = col->size;
  while (h != master) {
    if (h->size < size) {
      col = h;
      size = col->size;
    }
    h = h->right;
  }
  return col;
}

void cover(column_object* col) {
  column_object* row = col->down;
  col->right->left = col->left;
  col->left->right = col->right;
  while (row != col) {
    row = row->right;
    while (row->column_top != col) {
      row->up->down = row->down;
      row->down->up = row->up;
      row->column_top->size--;
      row = row->right;
    }
    row = row->down;
  }
}

void search_solutions(int k) {
  column_object* col;
  if (master->right == master) {
    solution.push_back(copy_current());
    return;
  }
  col = smallest_column();
}

void solve_sudoku() {}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < SIZE; ++i) cin >> raw_sudoku[i];
  process_board();
  construct_matrix();
  solve_sudoku();
  return 0;
}
