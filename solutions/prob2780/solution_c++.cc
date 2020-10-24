/*
 * Baekjoon Online Judge #2780
 * https://www.acmicpc.net/problem/2780
 */

#include <bits/stdc++.h>

using namespace std;

int in_t, in_n, dp[1001][11];
const vector<vector<int>> password_table = {
    {7}, {2, 4}, {1, 3, 5}, {2, 6}, {1, 5, 7}, {2, 4, 6, 8}, {3, 5, 9},
    {4, 8, 0}, {5, 7, 9}, {6, 8}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
};
const int MOD = 1234567;

int password_count(int len, int last) {
    if (len == 0) return 1;
    int &ret = dp[len][last];
    if (ret != -1) return ret;
    ret = 0;
    for (int next: password_table[last]) {
        ret = (ret + password_count(len - 1, next)) % MOD;
    }
    return ret % MOD;
}

int main() {
    scanf("%d", &in_t);
    memset(dp, -1, sizeof dp);
    while (in_t--) {
        scanf("%d", &in_n);
        printf("%d\n", password_count(in_n, 10));
    }
    return 0;
}
