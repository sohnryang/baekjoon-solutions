/*
 * Baekjoon Online Judge #16968
 * https://www.acmicpc.net/problem/16968
 */

#include <bits/stdc++.h>

using namespace std;

char in_format[5];
int len, dp[5][40];

int plates(int start, int last_used) {
    if (start == len) return 1;
    int &ret = dp[start][last_used];
    if (ret != -1) return ret;
    int start_id = in_format[start] == 'd' ? 0 : 11;
    int end_id = in_format[start] == 'd' ? 9 : 36;
    ret = 0;
    for (int id = start_id; id <= end_id; ++id)
        if (id != last_used)
            ret += plates(start + 1, id);
    return ret;
}

int main() {
    scanf("%s", in_format);
    memset(dp, -1, sizeof(dp));
    len = strlen(in_format);
    int last_used;
    if (in_format[0] == 'd') last_used = 11;
    else last_used = 0;
    printf("%d\n", plates(0, last_used));
}
