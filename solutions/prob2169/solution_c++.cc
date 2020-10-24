/*
 * Baekjoon Online Judge #2169
 * https://www.acmicpc.net/problem/2169
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_m, in_map[1001][1001], dp[1001][1001][3];
const int LEFT = 0, RIGHT = 1, DOWN = 2, NEGINF = -987654321;
bool cached[1001][1001][3];

inline bool in_range(int y, int x) {
    return y >= 0 && y < in_n && x >= 0 && x < in_m;
}

int travel(int y, int x, int dir) {
    if (y == in_n - 1 && x == in_m - 1) return in_map[y][x];
    if (!in_range(y, x)) return NEGINF;
    int &ret = dp[y][x][dir];
    if (cached[y][x][dir]) return ret + in_map[y][x];
    if (dir == LEFT)
        ret = max(travel(y, x - 1, LEFT), travel(y + 1, x, DOWN));
    else if (dir == RIGHT)
        ret = max(travel(y, x + 1, RIGHT), travel(y + 1, x, DOWN));
    else
        ret = max(max(travel(y, x + 1, RIGHT), travel(y, x - 1, LEFT)),
                  travel(y + 1, x, DOWN));
    cached[y][x][dir] = true;
    return ret + in_map[y][x];
}

int main() {
    memset(in_map, -1, sizeof(in_map));
    memset(cached, false, sizeof(cached));
    scanf("%d %d", &in_n, &in_m);
    for (int y = 0; y < in_n; ++y)
        for (int x = 0; x < in_m; ++x)
            scanf("%d", &in_map[y][x]);
    printf("%d\n", travel(0, 0, RIGHT));
    return 0;
}
