/*
 * Baekjoon Online Judge #12851
 * https://www.acmicpc.net/problem/12851
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();
int in_n, in_k;

inline bool in_range(int pos) {
    return pos >= 0 && pos <= 100000;
}

pair<int, int> shortest_path() {
    int dist[100001], paths[100001];
    bool visited[100001];
    for (int i = 0; i < 100001; ++i) dist[i] = INF;
    memset(paths, -1, sizeof(paths));
    memset(visited, false, sizeof(visited));
    dist[in_n] = 0;
    paths[in_n] = 1;
    visited[in_n] = true;
    queue<int> q;
    q.push(in_n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int nextpos[3] = {u - 1, u + 1, u * 2};
        for (int j = 0; j < 3; ++j) {
            if (!in_range(nextpos[j])) continue;
            if (!visited[nextpos[j]]) {
                q.push(nextpos[j]);
                visited[nextpos[j]] = true;
            }
            if (dist[nextpos[j]] > dist[u] + 1) {
                dist[nextpos[j]] = dist[u] + 1;
                paths[nextpos[j]] = paths[u];
            } else if (dist[nextpos[j]] == dist[u] + 1) {
                paths[nextpos[j]] += paths[u];
            }
        }
    }
    return make_pair(dist[in_k], paths[in_k]);
}

int main() {
    scanf("%d %d", &in_n, &in_k);
    auto result = shortest_path();
    printf("%d\n%d\n", result.first, result.second);
    return 0;
}
