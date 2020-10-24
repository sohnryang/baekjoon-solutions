/*
 * Baekjoon Online Judge #1562
 * https://www.acmicpc.net/problem/1562
 */

#include <bitset>
#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1'000'000'000;
int N, dp[101][1 << 10][10];

int step_num(int len, int used, int last_digit) {
    if (len < 10 - __builtin_popcount(used)) return 0;
    if (len == 0) return 1;
    if (last_digit == -1) {
        int result = 0;
        for (int i = 1; i < 10; ++i) {
            bitset<10> use = 0;
            use[i] = 1;
            result += step_num(len - 1, (int)use.to_ulong(), i);
            result %= MOD;
        }
        return result % MOD;
    } else {
        int &ret = dp[len][used][last_digit];
        if (ret != -1) return ret;
        ret = 0;
        if (last_digit - 1 >= 0 && last_digit - 1 < 10) {
            bitset<10> use = used;
            use[last_digit - 1] = 1;
            ret += step_num(len - 1, (int)use.to_ulong(), last_digit - 1);
            ret %= MOD;
        }
        if (last_digit + 1 >= 0 && last_digit + 1 < 10) {
            bitset<10> use = used;
            use[last_digit + 1] = 1;
            ret += step_num(len - 1, (int)use.to_ulong(), last_digit + 1);
            ret %= MOD;
        }
        return ret % MOD;
    }
}

int main() {
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", step_num(N, 0, -1));
    return 0;
}
