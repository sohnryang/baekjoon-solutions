/*
 * Baekjoon Online Judge #2156
 * https://www.acmicpc.net/problem/2156
 */

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int in_n, in_wines[10001], dp[10002][3];

int drink() {
    memset(dp, 0, sizeof(dp));
    for (int i = in_n - 1; i >= 0; --i) {
        dp[i][0] = max(dp[i + 1][1], dp[i + 2][0]) + in_wines[i];
        dp[i][1] = max(dp[i + 1][2], dp[i + 2][0]) + in_wines[i];
        dp[i][2] = dp[i + 2][0];
    }
    return max(dp[0][0], dp[1][0]);
}

int main() {
    scanf("%d", &in_n);
    memset(in_wines, -1, sizeof(in_wines));
    for (int i = 0; i < in_n; ++i)
        scanf("%d", &in_wines[i]);
    printf("%d\n", drink());
    return 0;
}