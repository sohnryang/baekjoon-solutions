/*
 * Baekjoon Online Judge #1753
 * https://www.acmicpc.net/problem/1753
 */

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ipair;

int V, E, K;
vector<pair<int, int>> graph[20001];
const int INF = 987654321;

void dijkstra() {
    vector<int> dist(V + 1, INF);
    dist[K] = 0;
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
    pq.push(make_pair(0, K));
    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (int j = 0; j < graph[u].size(); ++j) {
            auto v = graph[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }
    for (int i = 1; i <= V; ++i) {
        if (dist[i] >= INF) printf("INF\n");
        else printf("%d\n", dist[i]);
    }
}

int main() {
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v, w));
    }
    dijkstra();
    return 0;
}
