/*
 * Baekjoon Online Judge #1086
 * https://www.acmicpc.net/problem/1086
 */

#include <cstdio>
#include <cstring>
#include <numeric>
#include <string>

using namespace std;

const int MAX_N = 16, MAX_K = 101;
int N, K, mods[MAX_N], p10[51], d[MAX_N];
long long dp[1 << MAX_N][MAX_K];
string S[MAX_N];

int modulo(string num, int a) {
    int result = 0;
    for (int i = 0; i < num.length(); ++i)
        result = (result * 10 + (int)num[i] - '0') % a;
    return result;
}

long long divisible_seq(int used, int mod) {
    if (used == (1 << N) - 1) return mod == 0;
    auto &ret = dp[used][mod];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < N; ++i) {
        int mask = 1 << i;
        if (used & mask) continue;
        ret += divisible_seq(used | mask, (mod * p10[d[i]] + mods[i]) % K);
    }
    return ret;
}

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) result *= i;
    return result;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        char raw[51];
        scanf("%s", raw);
        S[i] = raw;
        d[i] = S[i].length();
    }
    scanf("%d", &K);
    p10[0] = 1 % K;
    for (int i = 1; i <= 50; ++i) p10[i] = p10[i - 1] * 10 % K;
    for (int i = 0; i < N; ++i) mods[i] = modulo(S[i], K);
    memset(dp, -1, sizeof(dp));
    auto seq_count = divisible_seq(0, 0);
    auto total_count = factorial(N);
    if (seq_count == 0) printf("0/1\n");
    else if (seq_count == total_count) printf("1/1\n");
    else {
        long long a = seq_count / gcd(seq_count, total_count);
        long long b = total_count / gcd(seq_count, total_count);
        printf("%lld/%lld\n", a, b);
    }
    return 0;
}
