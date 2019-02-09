/*
 * Baekjoon Online Judge #2206
 * https://www.acmicpc.net/problem/2206
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_m, in_map[1001][1001], dist[1001][1001][2];
const int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

inline bool in_range(int y, int x) {
    return y >= 0 && y < in_n && x >= 0 && x < in_m;
}

int shortest_path() {
    memset(dist, -1, sizeof(dist));
    dist[0][0][1] = 1;
    auto here = make_pair(make_pair(0, 0), 1);
    queue<pair<pair<int, int>, int>> q;
    q.push(here);
    while (!q.empty()) {
        here = q.front();
        int herey = here.first.first;
        int herex = here.first.second;
        int crack = here.second;
        q.pop();
        if (herey == in_n - 1 && herex == in_m - 1)
            return dist[herey][herex][crack];
        for (int j = 0; j < 4; ++j) {
            int therey = herey + dy[j];
            int therex = herex + dx[j];
            if (!in_range(therey, therex)) continue;
            if (in_map[therey][therex] && here.second) {
                dist[therey][therex][crack-1] = dist[herey][herex][crack] + 1;
                q.push(make_pair(make_pair(therey, therex), crack - 1));
            } else if (!in_map[therey][therex] && dist[therey][therex][crack] == -1) {
                dist[therey][therex][crack] = dist[herey][herex][crack] + 1;
                q.push(make_pair(make_pair(therey, therex), crack));
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &in_n, &in_m);
    memset(in_map, -1, sizeof(in_map));
    for (int y = 0; y < in_n; ++y) {
        char in_line[1001];
        scanf("%s", in_line);
        for (int x = 0; x < in_m; ++x)
            in_map[y][x] = in_line[x] - '0';
    }
    printf("%d\n", shortest_path());
    return 0;
}
