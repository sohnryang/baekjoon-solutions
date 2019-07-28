/*
 * Baekjoon Online Judge #9251
 * https://www.acmicpc.net/problem/9251
 */

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char in_a[1001], in_b[1001];
int len_a, len_b, dp[1001][1001];

int lcs(int n, int m) {
    if (n == -1 || m == -1)
        return 0;
    int &ret = dp[n][m];
    if (ret != -1) return ret;
    ret = 0;
    if (in_a[n] == in_b[m]) ret = max(ret, lcs(n - 1, m - 1) + 1);
    else {
        ret = max(ret, lcs(n - 1, m));
        ret = max(ret, lcs(n, m - 1));
    }
    return ret;
}

int main() {
    scanf("%s", in_a);
    scanf("%s", in_b);
    len_a = strlen(in_a);
    len_b = strlen(in_b);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", lcs(len_a - 1, len_b - 1));
    return 0;
}