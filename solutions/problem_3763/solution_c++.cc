/*
 * Baekjoon Online Judge #3763
 * https://www.acmicpc.net/problem/3763
 */

#include <ios>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
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
      sudoku[i][j] = c == '-' ? -1 : c - 'A';
    }
}

int box_num(int i, int j) { return i / BOX_SIZE * BOX_SIZE + j / BOX_SIZE; }

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
        col->size = 0;
        headers.push_back(col);
        prev_col = col;
      }
    }
  }
  master->left = prev_col;
  prev_col->right = master;
}

void construct_rows() {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      int val = sudoku[i][j];
      int a = val != -1 ? val : 0, b = val != -1 ? val + 1 : SIZE;
      for (int k = a; k < b; ++k) {
        int grid_col = i * SIZE + j;
        column_object* last = headers[grid_col]->up;
        column_object* grid_row = new column_object();
        grid_row->name = {i, j, k};
        grid_row->up = last;
        last->down = grid_row;
        grid_row->down = headers[grid_col];
        headers[grid_col]->up = grid_row;
        grid_row->column_top = headers[grid_col];
        headers[grid_col]->size++;

        int row_col = SIZE * SIZE + i * SIZE + k;
        last = headers[row_col]->up;
        column_object* row_row = new column_object();
        row_row->name = {i, j, k};
        row_row->up = last;
        last->down = row_row;
        row_row->down = headers[row_col];
        headers[row_col]->up = row_row;
        grid_row->right = row_row;
        row_row->left = grid_row;
        row_row->column_top = headers[row_col];
        headers[row_col]->size++;

        int col_col = SIZE * SIZE * 2 + j * SIZE + k;
        last = headers[col_col]->up;
        column_object* col_row = new column_object();
        col_row->name = {i, j, k};
        col_row->up = last;
        last->down = col_row;
        col_row->down = headers[col_col];
        headers[col_col]->up = col_row;
        row_row->right = col_row;
        col_row->left = row_row;
        col_row->column_top = headers[col_col];
        headers[col_col]->size++;

        int box = box_num(i, j);
        int box_col = SIZE * SIZE * 3 + box * SIZE + k;
        last = headers[box_col]->up;
        column_object* box_row = new column_object();
        box_row->name = {i, j, k};
        box_row->up = last;
        last->down = box_row;
        box_row->down = headers[box_col];
        headers[box_col]->up = box_row;
        col_row->right = box_row;
        box_row->left = col_row;
        box_row->column_top = headers[box_col];
        box_row->right = grid_row;
        grid_row->left = box_row;
        headers[box_col]->size++;
      }
    }
  }
}

void construct_matrix() {
  construct_headers();
  construct_rows();
}

unordered_map<int, column_object*> current_solution;
char sudoku_solution[SIZE][SIZE];
bool finalized = false;

void finalize() {
  if (finalized) return;
  finalized = true;
  for (auto elem : current_solution) {
    int cell = get<2>(elem.second->name);
    if (cell == -1) continue;
    char sol = cell + 'A';
    int y = get<0>(elem.second->name);
    int x = get<1>(elem.second->name);
    cout << y << ' ' << x << ' ' << sol << ' ' << '\n';
    sudoku_solution[y][x] = sol;
  }
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) cout << sudoku_solution[i][j];
    cout << '\n';
  }
}

void cover(column_object* col) {
  col->right->left = col->left;
  col->left->right = col->right;
  for (column_object* i = col->down; i != col; i = i->down) {
    for (column_object* j = i->right; j != i; j = j->right) {
      j->down->up = j->up;
      j->up->down = j->down;
      j->column_top->size--;
    }
  }
}

void uncover(column_object* col) {
  for (column_object* i = col->up; i != col; i = i->up) {
    for (column_object* j = i->left; j != i; j = j->left) {
      j->column_top->size++;
      j->down->up = j;
      j->up->down = j;
    }
  }
  col->right->left = col;
  col->left->right = col;
}

void dlx(int k) {
  if (master->right == master) {
    finalize();
    return;
  }
  column_object* c = master->right;
  for (column_object* j = master->right; j != master; j = j->right)
    if (j->size < c->size) c = j;
  cover(c);
  for (column_object* r = c->down; r != c; r = r->down) {
    current_solution[k] = r;
    for (column_object* j = r->right; j != r; j = j->right)
      cover(j->column_top);
    dlx(k + 1);
    r = current_solution[k];
    c = r->column_top;
    for (column_object* j = r->left; j != r; j = j->left)
      uncover(j->column_top);
  }
  uncover(c);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < SIZE; ++i) cin >> raw_sudoku[i];
  process_sudoku();
  construct_matrix();
  dlx(0);
  return 0;
}
