/*
 * Baekjoon Online Judge #11727
 * https://www.acmicpc.net/problem/11727
 */

#include <cstdio>
#include <cstring>

using namespace std;

int in_n, dp[1001];
const int MOD = 10007;

int tiling(int n) {
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i)
        dp[i] = dp[i - 1] % MOD + 2 * dp[i - 2] % MOD;
    return dp[n] % MOD;
}

int main() {
    scanf("%d", &in_n);
    printf("%d\n", tiling(in_n));
    return 0;
}