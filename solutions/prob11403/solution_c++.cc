/*
 * Baekjoon Online Judge #11403
 * https://www.acmicpc.net/problem/11403
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_adj[101][101], result[101][101];
bool visited[101], first;

void dfs(int v) {
    if (visited[v]) return;
    if (!first) visited[v] = true;
    else first = false;
    for (int next = 0; next < in_n; ++next)
        if (in_adj[v][next]) dfs(next);
}

int main() {
    scanf("%d", &in_n);
    memset(in_adj, -1, sizeof in_adj);
    memset(result, 0, sizeof result);
    for (int y = 0; y < in_n; ++y)
        for (int x = 0; x < in_n; ++x)
            scanf("%d", &in_adj[y][x]);
    for (int i = 0; i < in_n; ++i) {
        first = true;
        memset(visited, false, sizeof visited);
        dfs(i);
        for (int j = 0; j < in_n; ++j)
            if (visited[j]) result[i][j] = 1;
    }
    for (int y = 0; y < in_n; ++y) {
        for (int x = 0; x < in_n; ++x)
            printf("%d ", result[y][x]);
        printf("\n");
    }
    return 0;
}
