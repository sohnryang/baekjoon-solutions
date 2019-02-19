/*
 * Baekjoon Online Judge #16946
 * https://www.acmicpc.net/problem/16946
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_m, in_map[1001][1001], result[1001][1001], visited[1001][1001];
map<int, int> size_table;
const int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

inline bool in_range(int y, int x) {
    return y >= 0 && y < in_n && x >= 0 && x < in_m;
}

int floodfill(int y, int x, int label) {
    if (!in_range(y, x)) return 0;
    if (in_map[y][x] != 0) return 0;
    if (visited[y][x]) return 0;
    visited[y][x] = 1;
    in_map[y][x] = label;
    int ret = 1;
    for (int i = 0; i < 4; ++i)
        ret += floodfill(y + dy[i], x + dx[i], label);
    return ret;
}

void mark_map() {
    int label = -2;
    memset(visited, 0, sizeof(visited));
    for (int y = 0; y < in_n; ++y) {
        for (int x = 0; x < in_m; ++x) {
            if (in_map[y][x] == 0) {
                size_table[label] = floodfill(y, x, label);
                label--;
            }
        }
    }
}

void crack_n_move() {
    for (int y = 0; y < in_n; ++y) {
        for (int x = 0; x < in_m; ++x) {
            if (in_map[y][x] < 0) {
                result[y][x] = 0;
                continue;
            }
            int result_val = 1;
            set<int> visited_set;
            for (int i = 0; i < 4; ++i) {
                int nexty = y + dy[i], nextx = x + dx[i];
                if (!in_range(nexty, nextx)) continue;
                int label = in_map[nexty][nextx];
                if (label >= 0) continue;
                if (visited_set.find(label) != visited_set.end()) continue;
                visited_set.insert(label);
                result_val += size_table[label];
            }
            result[y][x] = result_val % 10;
        }
    }
}

void print() {
    for (int y = 0; y < in_n; ++y) {
        for (int x = 0; x < in_m; ++x)
            printf("%d", result[y][x]);
        printf("\n");
    }
}

int main() {
    memset(in_map, -1, sizeof(in_map));
    memset(result, -1, sizeof(result));
    scanf("%d %d", &in_n, &in_m);
    for (int y = 0; y < in_n; ++y) {
        char input[1001];
        scanf("%s", input);
        for (int x = 0; x < in_m; ++x)
            in_map[y][x] = input[x] - '0';
    }
    mark_map();
    crack_n_move();
    print();
    return 0;
}
