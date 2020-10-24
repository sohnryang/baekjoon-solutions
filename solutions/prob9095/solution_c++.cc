/*
 * Baekjoon Online Judge #9095
 * https://www.acmicpc.net/problem/9095
 */

#include <cstdio>
#include <cstring>

int in_t, in_n, dp[11];

int add_123(int value) {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= in_n; ++i)
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    return dp[value];
}

int main() {
    memset(dp, 0, sizeof(dp));
    scanf("%d", &in_t);
    for (int i = 0; i < in_t; ++i) {
        scanf("%d", &in_n);
        printf("%d\n", add_123(in_n));
    }
    return 0;
}
