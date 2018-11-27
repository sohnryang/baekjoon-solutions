/*
 * Baekjoon Online Judge #11726
 * https://www.acmicpc.net/problem/11726
 */

#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 10007;
int in_n, dp[1001];

int tiling(int width) {
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= width; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    return dp[width];
}

int main() {
    memset(dp, 0, sizeof(dp));
    scanf("%d", &in_n);
    printf("%d\n", tiling(in_n));
    return 0;
}