/*
 * Baekjoon Online Judge #1005
 * https://www.acmicpc.net/problem/1005
 */

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int in_t, in_n, in_k, in_times[1001], in_seq[1001][1001], in_w, dp[1001];
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
    scanf("%d", &in_t);
    for (int i = 0; i < in_t; ++i) {
        memset(in_times, -1, sizeof(in_times));
        memset(in_seq, 0, sizeof(in_seq));
        memset(dp, -1, sizeof(dp));
        memset(is_dep, false, sizeof(is_dep));
        scanf("%d %d", &in_n, &in_k);
        for (int j = 1; j <= in_n; ++j)
            scanf("%d", &in_times[j]);
        for (int j = 0; j < in_k; ++j) {
            int a, b;
            scanf("%d %d", &a, &b);
            is_dep[b] = true;
            in_seq[a][b] = 1;
        }
        scanf("%d", &in_w);
        printf("%d\n", construct(in_w));
    }
    return 0;
}