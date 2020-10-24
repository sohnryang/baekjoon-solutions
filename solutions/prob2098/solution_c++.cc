/*
 * Baekjoon Online Judge #2098
 * https://www.acmicpc.net/problem/2098
 */

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 17, INF = 987654321;
int N, dist[MAX_N][MAX_N], dp[MAX_N][1 << MAX_N];

int tsp(int here, int visited) {
    if (visited == (1 << N) - 1) return dist[here][0] ? dist[here][0] : INF;
    int &ret = dp[here][visited];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 0; i < N; ++i) {
        int mask = 1 << i;
        if (mask & visited) continue;
        if (dist[here][i] == 0) continue;
        int visiting = mask | visited;
        ret = min(ret, dist[here][i] + tsp(i, visiting));
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < N; ++x)
            scanf("%d", &dist[y][x]);
    printf("%d\n", tsp(0, 1));
    return 0;
}
