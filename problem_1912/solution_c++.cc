/*
 * Baekjoon Online Judge #1912
 * https://www.acmicpc.net/problem/1912
 */

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int in_n, in_seq[100001], dp[100001];

int maxsum() {
    dp[0] = in_seq[0];
    for (int n = 1; n < in_n; ++n)
        dp[n] = max(0, dp[n - 1]) + in_seq[n];
    int result = -1001;
    for (int i = 0; i < in_n; ++i)
        result = max(result, dp[i]);
    return result;
}

int main() {
    scanf("%d", &in_n);
    for (int i = 0; i < in_n; ++i)
        scanf("%d", &in_seq[i]);
    memset(dp, 0, sizeof(dp));
    printf("%d\n", maxsum());
}