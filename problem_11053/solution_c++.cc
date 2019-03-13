/*
 * Baekjoon Online Judge #11053
 * https://www.acmicpc.net/problem/11053
 */

#include <bits/stdc++.h>

using namespace std;

int N, A[1001], dp[1001];

int lis() {
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 1; i < N; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (A[i] > A[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    }
    return *max_element(dp, dp + N);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
    printf("%d\n", lis());
    return 0;
}
