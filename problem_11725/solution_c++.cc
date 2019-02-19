/*
 * Baekjoon Online Judge #11725
 * https://www.acmicpc.net/problem/11725
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, parent[100001];
vector<int> in_edges[100001];
bool visited[100001];

void dfs(int here) {
    if (visited[here]) return;
    visited[here] = true;
    for (int there: in_edges[here]) {
        if (!visited[there]) {
            parent[there] = here;
            dfs(there);
        }
    }
}

int main() {
    scanf("%d", &in_n);
    memset(parent, -1, sizeof(parent));
    memset(visited, false, sizeof(visited));
    for (int i = 1; i < in_n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        in_edges[a].push_back(b);
        in_edges[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= in_n; ++i)
        printf("%d\n", parent[i]);
    return 0;
}
