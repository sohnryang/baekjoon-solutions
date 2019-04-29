/*
 * Baekjoon Online Judge #7569
 * https://www.acmicpc.net/problem/7569
 */

#include <bits/stdc++.h>

using namespace std;

int M, N, H, B[101][101][101];
const int dx[] = {-1, 0, 0, 0, 0, 1};
const int dy[] = {0, -1, 0, 0, 1, 0};
const int dz[] = {0, 0, -1, 1, 0, 0};

inline bool reachable(int z, int y, int x) {
    return z >= 0 && z < H && y >= 0 && y < N && x >= 0 && x < M && \
        B[z][y][x] != -1;
}

int bfs() {
    int dist[101][101][101];
    memset(dist, -1, sizeof dist);
    queue<pair<pair<int, int>, int> > q;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < M; ++k)
                if (B[i][j][k] == 1)
                    dist[i][j][k] = 0, q.push(make_pair(make_pair(i, j), k));
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int u_z = u.first.first, u_y = u.first.second, u_x = u.second;
        for (int i = 0; i < 6; ++i) {
            int nextz = u_z + dz[i], nexty = u_y + dy[i], nextx = u_x + dx[i];
            if (!reachable(nextz, nexty, nextx)) continue;
            if (dist[nextz][nexty][nextx] != -1) continue;
            dist[nextz][nexty][nextx] = dist[u_z][u_y][u_x] + 1;
            q.push(make_pair(make_pair(nextz, nexty), nextx));
        }
    }
    int result = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (reachable(i, j, k) && dist[i][j][k] == -1)
                    return -1;
                result = max(result, dist[i][j][k]);
            }
        }
    }
    return result;
}

int main() {
    scanf("%d %d %d", &M, &N, &H);
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < M; ++k)
                scanf("%d", &B[i][j][k]);
    printf("%d\n", bfs());
    return 0;
}
