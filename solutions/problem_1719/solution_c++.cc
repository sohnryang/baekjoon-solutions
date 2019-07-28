/*
 * Baekjoon Online Judge #1719
 * https://www.acmicpc.net/problem/1719
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_m, dist[201][201], next_edge[201][201];
const int INF = 987654321;

int main() {
    scanf("%d %d", &in_n, &in_m);
    memset(dist, 0, sizeof(dist));
    memset(next_edge, 0, sizeof(next_edge));
    for (int y = 0; y < 201; ++y)
        for (int x = 0; x < 201; ++x)
            if (y != x)
                dist[y][x] = INF;
    for (int i = 0; i < in_m; ++i) {
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        dist[a][b] = d;
        dist[b][a] = d;
        next_edge[a][b] = b;
        next_edge[b][a] = a;
    }
    for (int k = 1; k <= in_n; ++k)
        for (int i = 1; i <= in_n; ++i)
            for (int j = 1; j <= in_n; ++j)
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next_edge[i][j] = next_edge[i][k];
                }
    for (int y = 1; y <= in_n; ++y) {
        for (int x = 1; x <= in_n; ++x) {
            if (y == x) printf ("- ");
            else if (y != x) printf("%d ", next_edge[y][x]);
        }
        printf("\n");
    }
    return 0;
}
