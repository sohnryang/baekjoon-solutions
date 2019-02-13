/*
 * Baekjoon Online Judge #1516
 * https://www.acmicpc.net/problem/1516
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_times[1001], in_seq[1001][1001], in_w, dp[1001];
bool is_dep[1001];

int construct(int building) {
    int &ret = dp[building];
    if (ret != -1) return ret + in_times[building];
    if (!is_dep[building]) return in_times[building];
    for (int i = 1; i <= in_n; ++i)
        if (in_seq[i][building] == 1)
            ret = max(ret, construct(i));
    return ret + in_times[building];
}

int main() {
    memset(in_times, -1, sizeof(in_times));
    memset(in_seq, 0, sizeof(in_seq));
    memset(dp, -1, sizeof(dp));
    memset(is_dep, false, sizeof(is_dep));
    scanf("%d", &in_n);
    for (int i = 1; i <= in_n; ++i) {
        int a, b;
        scanf("%d", &a);
        in_times[i] = a;
        while (true) {
            scanf("%d", &b);
            if (b == -1) break;
            is_dep[i] = true;
            in_seq[b][i] = 1;
        }
    }
    for (int i = 1; i <= in_n; ++i)
        printf("%d\n", construct(i));
    return 0;
}
