/*
 * Baekjoon Online Judge #1260
 * https://www.acmicpc.net/problem/1260
 */

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int in_n, in_m, in_v, in_graph[1001][1001];
bool visited[1001];

void dfs(int v) {
    visited[v] = true;
    printf("%d ", v);
    for (int i = 1; i <= in_n; ++i)
        if (in_graph[v][i] == 1 && !visited[i])
            dfs(i);
}

void bfs(int v) {
    queue<int> q;
    visited[v] = true;
    q.push(v);
    while (!q.empty()) {
        int s = q.front();
        printf("%d ", s);
        q.pop();
        for (int i = 1; i <= in_n; ++i) {
            if (in_graph[s][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &in_n, &in_m, &in_v);
    memset(in_graph, 0, sizeof(in_graph));
    for (int i = 0; i < in_m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        in_graph[a][b] = in_graph[b][a] = 1;
    }
    memset(visited, false, sizeof(visited));
    dfs(in_v);
    printf("\n");
    memset(visited, false, sizeof(visited));
    bfs(in_v);
    printf("\n");
    return 0;
}
