/*
 * Baekjoon Online Judge #1559
 * https://www.acmicpc.net/problem/1559
 */

#include <cstring>
#include <ios>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int dist[100][100][256][4], M, N, K;

tuple<int, int> next_pos(int y, int x, int now,
                         const vector<vector<int>> &maze) {
  int dir = (maze[y][x] + now) % 4;
  switch (dir) {
  case 0:
    return {y - 1, x};
  case 1:
    return {y, x + 1};
  case 2:
    return {y + 1, x};
  }
  return {y, x - 1};
}

bool is_in_range(int y, int x) { return 0 <= y && y < M && 0 <= x && x < N; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    cin >> M >> N;
    if (M == 0 && N == 0)
      break;
    vector<vector<int>> init_maze, boxes;
    for (int y = 0; y < M; y++) {
      string line_str;
      vector<int> line, boxes_line(N, -1);
      cin >> line_str;
      for (int x = 0; x < N; x++) {
        int cell = -1;
        switch (line_str[x]) {
        case 'N':
          cell = 0;
          break;
        case 'E':
          cell = 1;
          break;
        case 'S':
          cell = 2;
          break;
        case 'W':
          cell = 3;
          break;
        }
        line.push_back(cell);
      }
      boxes.push_back(boxes_line);
      init_maze.push_back(line);
    }
    cin >> K;
    for (int box_id = 0; box_id < K; box_id++) {
      int box_y, box_x;
      cin >> box_y >> box_x;
      boxes[box_y - 1][box_x - 1] = box_id;
    }
    memset(dist, -1, sizeof(dist));
    dist[0][0][0][0] = 0;
    queue<tuple<int, int, unsigned int, char>> q;
    q.push({0, 0, 0, 0});
    while (!q.empty()) {
      auto [here_y, here_x, here_collected, here_time_mod] = q.front();
      q.pop();
      int here_dist = dist[here_y][here_x][here_collected][here_time_mod];
      if (here_y == M - 1 && here_x == N - 1 &&
          here_collected == (1 << K) - 1) {
        cout << here_dist << "\n";
        break;
      }
      int there_dist = here_dist + 1;
      auto [there_y, there_x] = next_pos(here_y, here_x, here_dist, init_maze);
      int there_time_mod = (here_time_mod + 1) % 4;
      if (dist[here_y][here_x][here_collected][there_time_mod] == -1) {
        dist[here_y][here_x][here_collected][there_time_mod] = there_dist;
        q.push({here_y, here_x, here_collected, there_time_mod});
      }
      if (!is_in_range(there_y, there_x)) {
        continue;
      }
      unsigned int there_collected = here_collected;
      int box_id = boxes[there_y][there_x];
      if (box_id != -1)
        there_collected |= (1 << box_id);
      if (dist[there_y][there_x][there_collected][there_time_mod] == -1) {
        dist[there_y][there_x][there_collected][there_time_mod] = there_dist;
        q.push({there_y, there_x, there_collected, there_time_mod});
      }
    }
  }

  return 0;
}
