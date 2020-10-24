/*
 * Baekjoon Online Judge #2583
 * https://www.acmicpc.net/problem/2583
 */

#include <bits/stdc++.h>

using namespace std;

int in_m, in_n, in_k, in_paper[101][101];
const int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
vector<int> size_table;

inline bool in_range(int y, int x) {
    return y >= 0 && y < in_m && x >= 0 && x < in_n;
}

int dfs(int y, int x) {
    if (!in_range(y, x)) return 0;
    if (in_paper[y][x]) return 0;
    int result = 1;
    in_paper[y][x] = 1;
    for (int i = 0; i < 4; ++i)
        result += dfs(y + dy[i], x + dx[i]);
    return result;
}

void floodfill() {
    for (int y = 0; y < in_m; ++y)
        for (int x = 0; x < in_n; ++x)
            if (in_paper[y][x] == 0)
                size_table.push_back(dfs(y, x));
}

int main() {
    scanf("%d %d %d", &in_m, &in_n, &in_k);
    memset(in_paper, 0, sizeof in_paper);
    for (int i = 0; i < in_k; ++i) {
        int in_x1, in_y1, in_x2, in_y2;
        scanf("%d %d %d %d", &in_x1, &in_y1, &in_x2, &in_y2);
        for (int y = in_y1; y < in_y2; ++y)
            for (int x = in_x1; x < in_x2; ++x)
                in_paper[y][x] = 1;
    }
    floodfill();
    sort(size_table.begin(), size_table.end());
    printf("%d\n", size_table.size());
    for (int size: size_table) printf("%d ", size);
    printf("\n");
    return 0;
}
