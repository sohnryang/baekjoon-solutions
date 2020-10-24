/*
 * Baekjoon Online Judge #1600
 * https://www.acmicpc.net/problem/1600
 */

#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int K, W, H, G[201][201];
const int dy[] = {-1, 0, 0, 1, -2, -2, -1, -1, 1, 1, 2, 2};
const int dx[] = {0, -1, 1, 0, -1, 1, -2, 2, -2, 2, -1, 1};

inline bool reachable(int y, int x) {
    return y >= 0 && y < H && x >= 0 && x < W && G[y][x] != 1;
}

int bfs() {
    int dist[201][201][31];
    memset(dist, -1, sizeof dist);
    queue<pair<pair<int, int>, int>> q;
    dist[0][0][K] = 0;
    if (W == 1 && H == 1) return 0;
    q.push(make_pair(make_pair(0, 0), K));
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int u_y = u.first.first;
        int u_x = u.first.second;
        int u_left = u.second;
        for (int i = 0; i < 12; ++i) {
            int nexty = u_y + dy[i], nextx = u_x + dx[i];
            if (i >= 4 && u_left < 1) continue;
            if (!reachable(nexty, nextx)) continue;
            if (dist[nexty][nextx][u_left - (i >= 4)] != -1) continue;
            dist[nexty][nextx][u_left - (i >= 4)] = \
                dist[u_y][u_x][u_left] + 1;
            q.push(make_pair(make_pair(nexty, nextx), u_left - (i >= 4)));
            if (nexty == H - 1 && nextx == W - 1)
                return dist[nexty][nextx][u_left - (i >= 4)];
        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &K, &W, &H);
    for (int y = 0; y < H; ++y)
        for (int x = 0; x < W; ++x)
            scanf("%d", &G[y][x]);
    printf("%d\n", bfs());
    return 0;
}
