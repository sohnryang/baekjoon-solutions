/*
 * Baekjoon Online Judge #9461
 * https://www.acmicpc.net/problem/9461
 */

#include <bits/stdc++.h>

using namespace std;

int in_t, in_n;
long long dp[101];

long long padovan(int n) {
    if (n < 4) return 1ll;
    long long &ret = dp[n];
    if (ret != -1ll) return ret;
    ret = padovan(n - 2) + padovan(n - 3);
    return ret;
}

int main() {
    scanf("%d", &in_t);
    while (in_t--) {
        scanf("%d", &in_n);
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", padovan(in_n));
    }
    return 0;
}
