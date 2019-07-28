/*
 * Baekjoon Online Judge #2667
 * https://www.acmicpc.net/problem/2667
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, grid[30][30];
const int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

inline bool in_range(int y, int x) {
    return (y >= 0 && y < in_n) && (x >= 0 && x < in_n);
}

int floodfill(int y, int x) {
    if (!in_range(y, x)) return 0;
    if (grid[y][x] != 1) return 0;
    int result = 1;
    grid[y][x] = 2;
    for (int i = 0; i < 4; ++i)
        result += floodfill(y + dy[i], x + dx[i]);
    return result;
}

int main() {
    scanf("%d", &in_n);
    memset(grid, 0, sizeof(grid));
    for (int y = 0; y < in_n; ++y) {
        char in_line[30];
        scanf("%s", in_line);
        for (int x = 0; x < in_n; ++x)
            grid[y][x] = in_line[x] - '0';
    }
    vector<int> result;
    for (int y = 0; y < in_n; ++y)
        for (int x = 0; x < in_n; ++x)
            if (grid[y][x] == 1)
                result.push_back(floodfill(y, x));
    sort(result.begin(), result.end());
    int len = result.size();
    printf("%d\n", len);
    for (int i = 0; i < len; ++i)
        printf("%d\n", result[i]);
    return 0;
}
