/*
 * Baekjoon Online Judge #1904
 * https://www.acmicpc.net/problem/1904
 */

#include <bits/stdc++.h>

using namespace std;

const int MOD = 15746;
int in_n, dp[1000001];

int count_binary(int n) {
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return dp[n] % MOD;
}

int main() {
    scanf("%d", &in_n);
    memset(dp, 0, sizeof(dp));
    printf("%d\n", count_binary(in_n));
    return 0;
}
