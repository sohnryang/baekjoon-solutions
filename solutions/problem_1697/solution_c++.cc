/*
 * Baekjoon Online Judge #1697
 * https://www.acmicpc.net/problem/1697
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_k;

inline bool in_range(int pos) {
    return pos >= 0 && pos <= 100000;
}

int shortest_path() {
    int dist[100001];
    memset(dist, -1, sizeof(dist));
    dist[in_n] = 0;
    queue<int> q;
    q.push(in_n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int nextpos[3] = {u - 1, u + 1, u * 2};
        for (int j = 0; j < 3; ++j) {
            if (in_range(nextpos[j]) && dist[nextpos[j]] == -1) {
                dist[nextpos[j]] = dist[u] + 1;
                q.push(nextpos[j]);
            }
        }
    }
    return dist[in_k];
}

int main() {
    scanf("%d %d", &in_n, &in_k);
    printf("%d\n", shortest_path());
    return 0;
}
