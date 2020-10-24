/*
 * Baekjoon Online Judge #10844
 * https://www.acmicpc.net/problem/10844
 */

#include <cstdio>
#include <cstring>

using namespace std;

int in_n, dp[101][10];
const int MOD=1000000000;

int step_number() {
    for (int i = 0; i < 10; ++i) dp[1][i] = 1;
    for (int i = 2; i <= in_n; ++i) {
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for (int j = 1; j <= 8; ++j)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
    }
    int result = 0;
    for (int i = 1; i < 10; ++i) result = (result + dp[in_n][i]) % MOD;
    return result % MOD;
}

int main() {
    scanf("%d", &in_n);
    memset(dp, 0, sizeof(dp));
    printf("%d\n", step_number());
}
