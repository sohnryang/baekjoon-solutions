/*
 * Baekjoon Online Judge #1958
 * https://www.acmicpc.net/problem/1958
 */

#include <bits/stdc++.h>

using namespace std;

char in_a[101], in_b[101], in_c[101];
int len_a, len_b, len_c, dp[101][101][101];

int lcs(int i, int j, int k) {
    if (i == -1 || j == -1 || k == -1)
        return 0;
    int &ret = dp[i][j][k];
    if (ret != -1) return ret;
    ret = 0;
    if (in_a[i] == in_b[j] && in_b[j] == in_c[k])
        ret = max(ret, lcs(i - 1, j - 1, k - 1) + 1);
    else {
        ret = max(ret, lcs(i - 1, j, k));
        ret = max(ret, lcs(i, j - 1, k));
        ret = max(ret, lcs(i, j, k - 1));
        ret = max(ret, lcs(i - 1, j - 1, k));
        ret = max(ret, lcs(i - 1, j, k - 1));
        ret = max(ret, lcs(i, j - 1, k - 1));
    }
    return ret;
}

int main() {
    scanf("%s", in_a);
    scanf("%s", in_b);
    scanf("%s", in_c);
    len_a = strlen(in_a);
    len_b = strlen(in_b);
    len_c = strlen(in_c);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", lcs(len_a - 1, len_b - 1, len_c - 1));
    return 0;
}
