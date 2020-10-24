/*
 * Baekjoon Online Judge #2294
 * https://www.acmicpc.net/problem/2294
 */

#include <bits/stdc++.h>

using namespace std;

int N, K, C[101], dp[10001][101];
const int INF = 987654321;

/*
 * coins(0, *) = 0
 * coins(<0, *) = INF
 * coins(n, k) = min(coins(n - k, k) + 1, coins(n, k + 1))
 */

int coins(int val, int last) {
    if (val == 0) return 0;
    if (val < 0) return INF;
    if (last >= N) return INF;
    int &ret = dp[val][last];
    if (ret != -1) return ret;
    ret = min(coins(val - C[last], last) + 1, coins(val, last + 1));
    return ret;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i)
        scanf("%d", &C[i]);
    memset(dp, -1, sizeof dp);
    int result = coins(K, 0);
    if (result >= INF) result = -1;
    printf("%d\n", result);
    return 0;
}
