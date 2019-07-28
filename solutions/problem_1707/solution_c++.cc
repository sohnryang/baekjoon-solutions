/*
 * Baekjoon Online Judge #1707
 * https://www.acmicpc.net/problem/1707
 */

#include <bits/stdc++.h>

using namespace std;

int in_k, in_v, in_e;
vector<int> in_adjlist[20002], color;

void init() {
    for (int i = 0; i < 20002; ++i)
        in_adjlist[i].clear();
    color.clear();
}

bool bipartie(int start) {
    if (color[start] != -1)
        return true;
    queue<int> q;
    q.push(start);
    color[start] = 0;
    bool is_bipartie = true;
    while (!q.empty() && is_bipartie) {
        int u = q.front();
        q.pop();
        for (int j = 0; j < in_adjlist[u].size(); ++j) {
            int v = in_adjlist[u][j];
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                is_bipartie = false;
                break;
            }
        }
    }
    return is_bipartie;
}

int main() {
    scanf("%d", &in_k);
    for (int i = 0; i < in_k; ++i) {
        scanf("%d %d", &in_v, &in_e);
        init();
        for (int j = 0; j < in_e; ++j) {
            int in_a, in_b;
            scanf("%d %d", &in_a, &in_b);
            in_adjlist[in_a].push_back(in_b);
            in_adjlist[in_b].push_back(in_a);
        }
        color.assign(in_v + 1, -1);
        bool is_bipartie = true;
        for (int j = 1; j <= in_v; ++j) {
            if (!bipartie(j)) {
                is_bipartie = false;
                break;
            }
        }
        printf(is_bipartie ? "YES\n" : "NO\n");
    }
    return 0;
}
