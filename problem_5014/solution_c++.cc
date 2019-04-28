/*
 * Baekjoon Online Judge #5014
 * https://www.acmicpc.net/problem/5014
 */

#include <bits/stdc++.h>

using namespace std;

int F, S, G, U, D, dist[1000001];

inline bool in_range(int x) {
    return x >= 1 && x <= F;
}

void bfs() {
    memset(dist, -1, sizeof dist);
    queue<int> q;
    dist[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == G) return;
        if (in_range(u + U) && dist[u + U] == -1) {
            dist[u + U] = dist[u] + 1;
            q.push(u + U);
        }
        if (in_range(u - D) && dist[u - D] == -1) {
            dist[u - D] = dist[u] + 1;
            q.push(u - D);
        }
    }
}

int main() {
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    bfs();
    if (dist[G] != -1) printf("%d\n", dist[G]);
    else printf("use the stairs\n");
    return 0;
}
