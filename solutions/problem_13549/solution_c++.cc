/*
 * Baekjoon Online Judge #13549
 * https://www.acmicpc.net/problem/13549
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> intpair;
const int INF = 987654321;
int in_n, in_k;

inline bool in_range(int pos) {
    return pos >= 0 && pos <= 100000;
}

int shortest_path() {
    vector<int> dist(100001, INF);
    dist[in_n] = 0;
    priority_queue<intpair, vector<intpair>, greater<intpair>> pq;
    pq.push(make_pair(0, in_n));
    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        vector<intpair> nextpos;
        nextpos.push_back(make_pair(0, u * 2));
        nextpos.push_back(make_pair(1, u - 1));
        nextpos.push_back(make_pair(1, u + 1));
        for (int j = 0; j < 3; ++j) {
            auto v = nextpos[j];
            if (in_range(v.second) && dist[u] + v.first < dist[v.second]) {
                dist[v.second] = dist[u] + v.first;
                pq.push(make_pair(dist[v.second], v.second));
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
