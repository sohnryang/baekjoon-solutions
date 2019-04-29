/*
 * Baekjoon Online Judge #14442
 * https://www.acmicpc.net/problem/14442
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, K, dist[1001][1001][11];
char m[1001][1001];
const int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

inline bool in_range(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M;
}

int bfs() {
    memset(dist, -1, sizeof dist);
    dist[0][0][K] = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), K));
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int y = u.first.first, x = u.first.second, crack = u.second;
        if (y == N - 1 && x == M - 1) return dist[y][x][crack] + 1;
        for (int i = 0; i < 4; ++i) {
            int nexty = y + dy[i], nextx = x + dx[i];
            if (!in_range(nexty, nextx)) continue;
            if (dist[nexty][nextx][crack] != -1) continue;
            if (m[nexty][nextx] == '1' && crack < 1) continue;
            dist[nexty][nextx][crack - (m[nexty][nextx] == '1')] = \
                                                         dist[y][x][crack] + 1;
            q.push(make_pair(make_pair(nexty, nextx),
                        crack - (m[nexty][nextx] == '1')));
        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; ++i)
        scanf("%s", m[i]);
    printf("%d\n", bfs());
    return 0;
}
