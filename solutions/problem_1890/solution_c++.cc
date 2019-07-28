/*
 * Baekjoon Online Judge #1890
 * https://www.acmicpc.net/problem/1890
 */

#include <bits/stdc++.h>

using namespace std;

long long in_n, in_grid[101][101], dp[101][101];

inline bool in_range(long long y, long long x) {
    return y >= 0ll && y < in_n && x >= 0ll && x < in_n;
}

long long paths(long long y, long long x) {
    if (!in_range(y, x)) return 0ll;
    if (y == in_n - 1ll && x == in_n - 1ll) return 1ll;
    if (in_grid[y][x] == 0) return 0;
    long long &ret = dp[y][x];
    if (ret != -1ll) return ret;
    ret = paths(y + in_grid[y][x], x) + paths(y, x + in_grid[y][x]);
    return ret;
}

int main() {
    scanf("%Ld", &in_n);
    memset(in_grid, -1, sizeof(in_grid));
    memset(dp, -1, sizeof(dp));
    for (int y = 0; y < in_n; ++y)
        for (int x = 0; x < in_n; ++x)
            scanf("%Ld", &in_grid[y][x]);
    printf("%Ld\n", paths(0ll, 0ll));
    return 0;
}
