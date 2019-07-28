/*
 * Baekjoon Online Judge #14501
 * https://www.acmicpc.net/problem/14501
 */

#include <bits/stdc++.h>

using namespace std;

int N, T[16], P[16], dp[16];

int resign(int n) {
    if (n >= N) return 0;
    int &ret = dp[n];
    if (ret != -1) return ret;
    if (n + T[n] <= N) ret = max(P[n] + resign(n + T[n]), resign(n + 1));
    else ret = resign(n + 1);
    return ret;
}

int main() {
    scanf("%d", &N);
    memset(T, 0, sizeof T);
    memset(P, 0, sizeof P);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < N; ++i) scanf("%d %d", &T[i], &P[i]);
    printf("%d\n", resign(0));
    return 0;
}
