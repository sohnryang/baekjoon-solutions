/*
 * Baekjoon Online Judge #2225
 * https://www.acmicpc.net/problem/2225
 */

#include <cstdio>
#include <cstring>

using namespace std;

int in_n, in_k, cache[201][201];
const int MOD = 1000000000;

int sum_ways(int n, int k) {
    if (k == 0) return n == 0 ? 1 : 0;
    if (n < 0 || k < 0) return 0;
    int &ret = cache[n][k];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i <= n; ++i)
        ret = (ret + sum_ways(n - i, k - 1)) % MOD;
    return ret % MOD;
}

int main() {
    scanf("%d %d", &in_n, &in_k);
    memset(cache, -1, sizeof(cache));
    printf("%d\n", sum_ways(in_n, in_k));
    return 0;
}
