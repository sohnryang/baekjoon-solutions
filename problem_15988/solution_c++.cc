/*
 * Baekjoon Online Judge #15988
 * https://www.acmicpc.net/problem/15988
 */

#include <bits/stdc++.h>

using namespace std;

int in_t, in_n, dp[1000001];
const int MOD = 1000000009;

int plus123(int n) {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; ++i)
        dp[i] = ((long long)dp[i - 1] + dp[i - 2] + dp[i - 3]) % (int)MOD;
    return dp[n] % MOD;
}

int main() {
    scanf("%d", &in_t);
    memset(dp, 0, sizeof(dp));
    while (in_t--) {
        scanf("%d", &in_n);
        printf("%d\n", plus123(in_n));
    }
    return 0;
}
