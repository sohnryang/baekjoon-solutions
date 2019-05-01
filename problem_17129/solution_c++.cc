/*
 * Baekjoon Online Judge #17129
 * https://www.acmicpc.net/problem/17129
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, dist[3001][3001];
const int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
char A[3001][3001];

inline bool reachable(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M && A[y][x] != '1';
}

int bfs() {
    memset(dist, -1, sizeof dist);
    queue<pair<int, int>> q;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (A[i][j] == '2')
                q.push(make_pair(i, j)), dist[i][j] = 0;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int y = u.first, x = u.second;
        for (int i = 0; i < 4; ++i) {
            int nexty = u.first + dy[i], nextx = u.second + dx[i];
            if (!reachable(nexty, nextx)) continue;
            if (dist[nexty][nextx] != -1) continue;
            dist[nexty][nextx] = dist[y][x] + 1;
            q.push(make_pair(nexty, nextx));
        }
    }
    int result = 987654321;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (A[i][j] >= '3' && A[i][j] <= '5')
                if (dist[i][j] != -1)
                    result = min(result, dist[i][j]);
    if (result == 987654321) return -1;
    return result;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i)
        scanf("%s", A[i]);
    int result = bfs();
    if (result == -1) printf("NIE\n");
    else printf("TAK\n%d\n", result);
    return 0;
}
