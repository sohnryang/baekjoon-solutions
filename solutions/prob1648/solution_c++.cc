/*
 * Baekjoon Online Judge #1648
 * https://www.acmicpc.net/problem/1648
 */

#include <cstdio>
#include <cstring>

const int MOD = 9901, MAX_N = 15;
int N, M, dp[MAX_N * MAX_N][1 << MAX_N];

int fill_board(int current, int next_filled) {
    if (current == N * M) return next_filled == 0;
    if (current > N * M) return 0;
    int &ret = dp[current][next_filled];
    if (ret != -1) return ret;
    ret = 0;
    if (next_filled % 2 == 1) ret = fill_board(current + 1, next_filled >> 1);
    else {
        ret += fill_board(current + 1, (next_filled | (1 << M)) >> 1);
        ret %= MOD;
        if (current % M <= M - 2 && next_filled % 4 == 0) {
            ret += fill_board(current + 2, next_filled >> 2);
            ret %= MOD;
        }
    }
    return ret;
}

int main() {
    scanf("%d %d", &N, &M);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", fill_board(0, 0));
    return 0;
}
