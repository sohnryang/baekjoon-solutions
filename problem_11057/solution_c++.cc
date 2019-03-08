/*
 * Baekjoon Online Judge #11057
 * https://www.acmicpc.net/problem/11057
 */

#include <bits/stdc++.h>

using namespace std;

int N, dp[1001][10];
const int MOD = 10007;

int slope_num(int len, int last) {
    if (len == 1) return 1;
    int &ret = dp[len][last];
    if (ret != -1) return ret % MOD;
    ret = 0;
    for (int i = last; i < 10; ++i) ret = (ret + slope_num(len - 1, i)) % MOD;
    return ret;
}

int main() {
    scanf("%d", &N);
    memset(dp, -1, sizeof dp);
    int result = 0;
    for (int i = 0; i < 10; ++i) result = (result + slope_num(N, i)) % MOD;
    printf("%d\n", result);
    return 0;
}
