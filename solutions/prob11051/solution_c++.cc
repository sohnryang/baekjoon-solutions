/*
 * Baekjoon Online Judge #11051
 * https://www.acmicpc.net/problem/11051
 */

#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
const int MOD = 10007;

int bino(int n, int k) {
    if (n == k || k == 0) return 1;
    int &ret = dp[n][k];
    if (ret != -1) return ret;
    ret = bino(n - 1, k - 1) + bino(n - 1, k);
    ret %= MOD;
    return ret;
}

int main() {
    int N, K;
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &N, &K);
    printf("%d\n", bino(N, K));
    return 0;
}
