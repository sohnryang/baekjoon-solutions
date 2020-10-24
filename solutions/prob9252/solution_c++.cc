/*
 * Baekjoon Online Judge #9252
 * https://www.acmicpc.net/problem/9252
 */

#include <bits/stdc++.h>

using namespace std;

char in_a[1001], in_b[1001], dir_table[1001][1001];
int len_a, len_b, dp[1001][1001];

int lcs(int n, int m) {
    if (n == -1 || m == -1)
        return 0;
    int &ret = dp[n][m];
    char &dir = dir_table[n][m];
    if (ret != -1) return ret;
    ret = 0;
    if (in_a[n] == in_b[m]) {
        ret = max(ret, lcs(n - 1, m - 1) + 1);
        dir = '\\';
    } else {
        int up = max(ret, lcs(n - 1, m));
        int left = max(ret, lcs(n, m - 1));
        ret = max(up, left);
        if (up > left) dir = '|';
        else dir = '-';
    }
    return ret;
}

void print_lcs(int n, int m) {
    if (n == -1 || m == -1) return;
    char &dir = dir_table[n][m];
    if (dir == '\\') {
        print_lcs(n - 1, m - 1);
        printf("%c", in_a[n]);
    }
    else if (dir == '|') print_lcs(n - 1, m);
    else print_lcs(n, m - 1);
}

int main() {
    scanf("%s", in_a);
    scanf("%s", in_b);
    len_a = strlen(in_a);
    len_b = strlen(in_b);
    memset(dp, -1, sizeof(dp));
    memset(dir_table, 0, sizeof(dir_table));
    printf("%d\n", lcs(len_a - 1, len_b - 1));
    print_lcs(len_a - 1, len_b - 1);
    printf("\n");
    return 0;
}
