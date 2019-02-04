/*
 * Baekjoon Online Judge #13913
 * https://www.acmicpc.net/problem/13913
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_k, parent[100001];
vector<int> path;

inline bool in_range(int pos) {
    return pos >= 0 && pos <= 100000;
}

int shortest_path() {
    int dist[100001];
    memset(dist, -1, sizeof(dist));
    memset(parent, -1, sizeof(parent));
    dist[in_n] = 0;
    parent[in_n] = in_n;
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
                parent[nextpos[j]] = u;
            }
        }
    }
    return dist[in_k];
}

void construct_path() {
    path.push_back(in_k);
    int v = in_k;
    while (parent[v] != v) {
        v = parent[v];
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
}

int main() {
    scanf("%d %d", &in_n, &in_k);
    printf("%d\n", shortest_path());
    construct_path();
    for (int i = 0; i < path.size(); ++i)
        printf("%d ", path[i]);
    return 0;
}
