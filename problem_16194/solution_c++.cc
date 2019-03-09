/*
 * Baekjoon Online Judge #16194
 * https://www.acmicpc.net/problem/16194
 */

#include <bits/stdc++.h>

using namespace std;

int N, P[1001], dp[1001];

int buy(int n) {
    if (n == 0) return 0;
    if (n < 0) return numeric_limits<int>::max();
    int &ret = dp[n];
    if (ret != -1) return ret;
    ret = numeric_limits<int>::max();
    for (int i = 1; i <= n; ++i)
        ret = min(ret, buy(n - i) + P[i]);
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &P[i]);
    memset(dp, -1, sizeof dp);
    printf("%d\n", buy(N));
    return 0;
}
