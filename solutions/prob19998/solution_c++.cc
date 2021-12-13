/*
 * Baekjoon Online Judge #19998
 * https://www.acmicpc.net/problem/19998
 */

#include <ios>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

int sudoku_grid[9][9];

struct Node {
  Node *left = nullptr;
  Node *right = nullptr;
  Node *up = nullptr;
  Node *down = nullptr;
  Node *col = nullptr;
  int size = -1;
  tuple<int, int, int> label;
};
Node root;
vector<Node> header;
unordered_map<int, Node *> solutions;

inline size_t encode_idx(int type, int i, int j) {
  return type * 81 + i * 9 + j;
}

inline int box_id(int y, int x) { return y / 3 * 3 + x / 3; }

void cover(Node *node) {
  node->right->left = node->left;
  node->left->right = node->right;
  for (Node *i = node->down; i != node; i = i->down)
    for (Node *j = i->right; j != i; j = j->right) {
      j->down->up = j->up;
      j->up->down = j->down;
      j->col->size--;
    }
}

void uncover(Node *node) {
  for (Node *i = node->up; i != node; i = i->up)
    for (Node *j = i->left; j != i; j = j->left) {
      j->col->size++;
      j->down->up = j;
      j->up->down = j;
    }
  node->right->left = node;
  node->left->right = node;
}

bool finished = false;
void print_solution() {
  if (finished)
    return;
  finished = true;
  for (auto elem : solutions) {
    auto [y, x, n] = elem.second->label;
    sudoku_grid[y][x] = n;
  }
  for (int y = 0; y < 9; ++y) {
    for (int x = 0; x < 9; ++x)
      cout << sudoku_grid[y][x] << " ";
    cout << "\n";
  }
}

void dlx(int k) {
  if (finished)
    return;
  if (root.right == &root) {
    print_solution();
    return;
  }
  Node *c = root.right;
  for (Node *j = c; j != &root; j = j->right)
    if (j->size < c->size)
      c = j;
  cover(c);
  for (Node *r = c->down; r != c; r = r->down) {
    solutions[k] = r;
    for (Node *j = r->right; j != r; j = j->right)
      cover(j->col);
    dlx(k + 1);
    r = solutions[k];
    c = r->col;
    for (Node *j = r->left; j != r; j = j->left)
      uncover(j->col);
  }
  uncover(c);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int y = 0; y < 9; ++y)
    for (int x = 0; x < 9; ++x)
      cin >> sudoku_grid[y][x];

  Node *last = &root;
  header.assign(9 * 9 * 4, {.size = 0});
  for (int t = 0; t < 4; ++t)
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        Node *here = &header[encode_idx(t, i, j)];
        here->left = last;
        here->left->right = here;
        here->right = &root;
        here->right->left = here;
        here->up = here;
        here->up->down = here;
        here->col = here;
        here->label = {t, i, j};
        last = here;
      }
  for (int y = 0; y < 9; ++y)
    for (int x = 0; x < 9; ++x) {
      Node *grid_header = &header[encode_idx(0, y, x)];
      for (int n = 1; n <= 9; ++n) {
        if (sudoku_grid[y][x] != 0 && sudoku_grid[y][x] != n)
          continue;
        Node *row_header = &header[encode_idx(1, y, n - 1)];
        Node *col_header = &header[encode_idx(2, x, n - 1)];
        Node *box_header = &header[encode_idx(3, box_id(y, x), n - 1)];
        Node *header_cells[] = {grid_header, row_header, col_header,
                                box_header};
        Node *grid_cell = new Node();
        Node *row_cell = new Node();
        Node *col_cell = new Node();
        Node *box_cell = new Node();
        Node *cells[] = {grid_cell, row_cell, col_cell, box_cell};
        for (int i = 0; i < 4; ++i) {
          header_cells[i]->size++;
          header_cells[i]->up->down = cells[i];
          header_cells[i]->up->down->up = header_cells[i]->up;
          header_cells[i]->up = cells[i];
          header_cells[i]->up->down = header_cells[i];
          cells[i]->right = cells[(i + 1) % 4];
          cells[i]->right->left = cells[i];
          cells[i]->col = header_cells[i];
          cells[i]->label = {y, x, n};
        }
      }
    }
  dlx(0);
  return 0;
}
