/*
 * Baekjoon Online Judge #1010
 * https://www.acmicpc.net/problem/1010
 */

#include <bits/stdc++.h>

int in_t, dp[31][31];

int bridges(int left, int right) {
    if (left == right) return 1;
    if (left == 1) return right;
    int &ret = dp[left][right];
    if (ret != -1) return ret;
    ret = 0;
    for (int r = right - 1; r >= left - 1; --r)
        ret += bridges(left - 1, r);
    return ret;
}

int main() {
    scanf("%d", &in_t);
    memset(dp, -1, sizeof(dp));
    while (in_t--) {
        int in_n, in_m;
        scanf("%d %d", &in_n, &in_m);
        printf("%d\n", bridges(in_n, in_m));
    }
    return 0;
}
