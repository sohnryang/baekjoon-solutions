/*
 * Baekjoon Online Judge #14940
 * https://www.acmicpc.net/problem/14940
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_m, in_grid[1001][1001], goalx, goaly;
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
map<pair<int, int>, int> dist;

inline bool available(pair<int, int> pos) {
    int y = pos.first, x = pos.second;
    return y >= 0 && y < in_n && x >= 0 && x < in_m && in_grid[y][x] == 1;
}

void shortest_path() {
    queue<pair<int, int>> q;
    auto here = make_pair(goaly, goalx);
    q.push(here);
    dist[here] = 0;
    while (!q.empty()) {
        here = q.front();
        q.pop();
        for (int j = 0; j < 4; ++j) {
            auto there = make_pair(here.first + dy[j], here.second + dx[j]);
            if (available(there) && dist.count(there) != 1) {
                dist[there] = dist[here] + 1;
                q.push(there);
            }
        }
    }
}

int main() {
    scanf("%d %d", &in_n, &in_m);
    memset(in_grid, -1, sizeof(in_grid));
    for (int y = 0; y < in_n; ++y) {
        for (int x = 0; x < in_m; ++x) {
            int in_num;
            scanf("%d", &in_num);
            if (in_num == 2) {
                goaly = y;
                goalx = x;
            }
            in_grid[y][x] = in_num;
        }
    }
    shortest_path();
    for (int y = 0; y < in_n; ++y) {
        for (int x = 0; x < in_m; ++x) {
            auto pos = make_pair(y, x);
            int num = 0;
            if (in_grid[y][x] != 0)
                num = dist.count(pos) != 1 ? -1 : dist[pos];
            else
                num = 0;
            printf("%d ", num);
        }
        printf("\n");
    }
    return 0;
}
