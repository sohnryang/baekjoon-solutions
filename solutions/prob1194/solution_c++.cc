/*
 * Baekjoon Online Judge #1194
 * https://www.acmicpc.net/problem/1194
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, dist[51][51][1 << 6 + 1];
char m[51][51];
const int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

inline int getkey(int before, char key) {
    bitset<6> b(before);
    b[key - 'a'] = 1;
    return (int)b.to_ulong();
}

inline bool in_range(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M;
}

inline bool reachable(int y, int x, int key) {
    if (!in_range(y, x)) return false;
    if (m[y][x] == '#') return false;
    if (m[y][x] >= 'A' && m[y][x] <= 'F') {
        bitset<6> b(key);
        return b[m[y][x] - 'A'];
    }
    return true;
}

int bfs() {
    memset(dist, -1, sizeof dist);
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (m[i][j] == '0')
                q.push(make_pair(make_pair(i, j), 0)), dist[i][j][0] = 0;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int ux = u.first.second, uy = u.first.first, ukey = u.second;
        if (m[uy][ux] >= 'a' && m[uy][ux] <= 'f') {
            if (getkey(ukey, m[uy][ux]) != ukey) {
                dist[uy][ux][getkey(ukey, m[uy][ux])] = dist[uy][ux][ukey];
                q.push(make_pair(make_pair(uy, ux), getkey(ukey, m[uy][ux])));
                continue;
            }
        }
        for (int i = 0; i < 4; ++i) {
            int nexty = u.first.first + dy[i], nextx = u.first.second + dx[i];
            if (!reachable(nexty, nextx, ukey)) continue;
            if (dist[nexty][nextx][ukey] != -1) continue;
            dist[nexty][nextx][ukey] = dist[uy][ux][ukey] + 1;
            q.push(make_pair(make_pair(nexty, nextx), ukey));
            if (m[nexty][nextx] == '1')
                return dist[nexty][nextx][ukey];
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) scanf("%s", m[i]);
    printf("%d\n", bfs());
    return 0;
}
