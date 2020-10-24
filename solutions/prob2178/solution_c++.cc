/*
 * Baekjoon Online Judge #2178
 * https://www.acmicpc.net/problem/2178
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_m, in_maze[101][101], dist[101][101];
const int dy[4] = {-1, 0, 0, 1}, dx[4] = {0, -1, 1, 0};

inline bool available(int y, int x) {
    return y >= 0 && y < in_n && x >= 0 && x < in_m && in_maze[y][x] == 1;
}

void shortest_path() {
    memset(dist, -1, sizeof(dist));
    dist[0][0] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        for (int j = 0; j < 4; ++j) {
            int next_y = u.first + dy[j], next_x = u.second + dx[j];
            if (dist[next_y][next_x] == -1 && available(next_y, next_x)) {
                dist[next_y][next_x] = dist[u.first][u.second] + 1;
                q.push(make_pair(next_y, next_x));
            }
        }
    }
}

int main() {
    scanf("%d %d", &in_n, &in_m);
    memset(in_maze, -1, sizeof(in_maze));
    for (int y = 0; y < in_n; ++y) {
        char line[101];
        scanf("%s", line);
        for (int x = 0; x < in_m; ++x)
            in_maze[y][x] = line[x] - '0';
    }
    shortest_path();
    printf("%d\n", dist[in_n - 1][in_m - 1]);
    return 0;
}
