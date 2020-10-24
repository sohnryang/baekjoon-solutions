/*
 * Baekjoon Online Judge #7562
 * https://www.acmicpc.net/problem/7562
 */

#include <bits/stdc++.h>

using namespace std;

int in_t, in_l, in_x1, in_y1, in_x2, in_y2;
const int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

inline bool in_range(int x, int y) {
    return y >= 0 && y < in_l && x >= 0 && x < in_l;
}

int move_knight() {
    int dist[301][301];
    memset(dist, -1, sizeof(dist));
    dist[in_x1][in_y1] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(in_x1, in_y1));
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        for (int j = 0; j < 8; ++j) {
            int next_x = u.first + dx[j], next_y = u.second + dy[j];
            if (dist[next_x][next_y] == -1 && in_range(next_x, next_y)) {
                dist[next_x][next_y] = dist[u.first][u.second] + 1;
                q.push(make_pair(next_x, next_y));
            }
        }
    }
    return dist[in_x2][in_y2];
}

int main() {
    scanf("%d", &in_t);
    while (in_t--) {
        scanf("%d", &in_l);
        scanf("%d %d", &in_x1, &in_y1);
        scanf("%d %d", &in_x2, &in_y2);
        printf("%d\n", move_knight());
    }
    return 0;
}
