/*
 * Baekjoon Online Judge #2606
 * https://www.acmicpc.net/problem/2606
 */

#include <bits/stdc++.h>

using namespace std;

int in_num, in_edges, in_adj[101][101];
bool infected[101];

void infect(int computer) {
    if (infected[computer])
        return;
    infected[computer] = true;
    for (int i = 1; i <= in_num; ++i)
        if (in_adj[computer][i] == 1)
            infect(i);
}

int main() {
    memset(infected, false, sizeof(infected));
    memset(in_adj, 0, sizeof(in_adj));
    scanf("%d", &in_num);
    scanf("%d", &in_edges);
    for (int i = 0; i < in_edges; ++i) {
        int in_a, in_b;
        scanf("%d %d", &in_a, &in_b);
        in_adj[in_a][in_b] = 1;
        in_adj[in_b][in_a] = 1;
    }
    infect(1);
    int result = 0;
    for (int i = 1; i <= in_num; ++i)
        result += infected[i];
    printf("%d\n", result - 1);
    return 0;
}
