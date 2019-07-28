/*
 * Baekjoon Online Judge #2579
 * https://www.acmicpc.net/problem/2579
 */
 
#include <algorithm>
#include <cstdio>
#include <cstring>
 
using namespace std;

int in_n, steps[301], dp[301][2];
 
int main() {
    scanf("%d", &in_n);
    memset(steps, -1, sizeof(steps));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < in_n; ++i)
        scanf("%d", &steps[i]);
    for (int i = 0; i < in_n; ++i) {
        dp[i][0] = dp[i - 1][1] + steps[i];
        dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + steps[i];
    }
    printf("%d\n", max(dp[in_n - 1][0], dp[in_n - 1][1]));
    return 0;
}