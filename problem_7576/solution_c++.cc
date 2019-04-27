#include <bits/stdc++.h>

using namespace std;

int M, N, G[1001][1001], d[1001][1001];
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

inline bool check(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M && G[y][x] != -1;
}

void bfs() {
    memset(d, -1, sizeof d);
    queue<pair<int, int>> q;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (G[i][j] == 1) {
                d[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nexty = u.first + dy[i], nextx = u.second + dx[i];
            if (!check(nexty, nextx)) continue;
            if (d[nexty][nextx] == -1) {
                d[nexty][nextx] = d[u.first][u.second] + 1;
                q.push(make_pair(nexty, nextx));
            }
        }
    }
}

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &G[i][j]);
    bfs();
    int result = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (check(i, j) && d[i][j] == -1) {
                printf("-1\n");
                return 0;
            }
            result = max(result, d[i][j]);
        }
    }
    printf("%d\n", result);
    return 0;
}
