/*
 * Baekjoon Online Judge #2011
 * https://www.acmicpc.net/problem/2011
 */

#include <cstdio>
#include <cstring>

using namespace std;

char in_cipher[5002];
int len, dp[5002];
const int MOD = 1000000;

int decrypt_ways() {
    dp[len] = 1;
    for (int n = len - 1; n >= 0; --n) {
        int num = in_cipher[n] - '0';
        if (num > 0 && num <= 26) dp[n] = dp[n] % MOD + dp[n + 1] % MOD;
        if (n != len - 1 && num != 0) {
            num = (in_cipher[n] - '0') * 10 + in_cipher[n + 1] - '0';
            if (num > 0 && num <= 26) dp[n] = dp[n] % MOD + dp[n + 2] % MOD;
        }
    }
    return dp[0] % MOD;
}

int main() {
    scanf("%s", in_cipher);
    len = strlen(in_cipher);
    memset(dp, 0, sizeof(dp));
    printf("%d\n", decrypt_ways());
    return 0;
}
