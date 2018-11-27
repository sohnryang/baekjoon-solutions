/*
 * Baekjoon Online Judge #2293
 * https://www.acmicpc.net/problem/2293
 */

#include <cassert>
#include <cstdio>
#include <cstring>

using namespace std;

int in_n, in_k, in_coins[101], dp[10001];

int coins(int value) {
    dp[0] = 1;
    for (int i = 0; i < in_n; ++i)
        for (int j = 1; j <= in_k; ++j)
            if (j >= in_coins[i])
                dp[j] += dp[j - in_coins[i]];
    return dp[value];
}

int main() {
    memset(in_coins, -1, sizeof(in_coins));
    memset(dp, 0, sizeof(dp));
    scanf("%d %d", &in_n, &in_k);
    for (int i = 0; i < in_n; ++i)
        scanf("%d", &in_coins[i]);
    printf("%d\n", coins(in_k));
    return 0;
}
