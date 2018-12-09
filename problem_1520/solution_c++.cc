/*
 * Baekjoon Online Judge #1520
 * https://www.acmicpc.net/problem/1520
 */

#include <cstdio>
#include <cstring>

using namespace std;

int in_m, in_n, in_grid[501][501], cache[501][501];

bool range_check(int y, int x) {
    bool result = y >= 0 && y < in_m && x >= 0 && x < in_n;
    return result;
}

int pathfind(int y, int x) {
    if (y == in_m - 1 && x == in_n - 1) return 1;
    if (!range_check(y, x)) return 0;
    int &ret = cache[y][x];
    if (ret != -1) return ret;
    int result = 0;
    if (in_grid[y][x] > in_grid[y + 1][x])
        result += pathfind(y + 1, x);
    if (in_grid[y][x] > in_grid[y - 1][x])
        result += pathfind(y - 1, x);
    if (in_grid[y][x] > in_grid[y][x + 1])
        result += pathfind(y, x + 1);
    if (in_grid[y][x] > in_grid[y][x - 1])
        result += pathfind(y, x - 1);
    ret = result;
    return ret;
}

int main() {
    scanf("%d %d", &in_m, &in_n);
    memset(in_grid, 0, sizeof(in_grid));
    for (int y = 0; y < in_m; ++y)
        for (int x = 0; x < in_n; ++x)
            scanf("%d", &in_grid[y][x]);
    memset(cache, -1, sizeof(cache));
    printf("%d\n", pathfind(0, 0));
    return 0;
}
