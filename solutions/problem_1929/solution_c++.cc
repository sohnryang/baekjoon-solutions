/*
 * Baekjoon Online Judge #1929
 * https://www.acmicpc.net/problem/1929
 */

#include <cstdio>
#include <cstring>

using namespace std;

int in_m, in_n;
bool prime_table[1000001];

void sieve() {
    for (int i = 0; i < 1000001; ++i) prime_table[i] = true;
    prime_table[1] = false;
    for (int i = 1; i < 1000001; ++i) {
        if (!prime_table[i]) continue;
        for (int j = i * 2; j < 1000001; j += i)
            prime_table[j] = false;
    }
}

int main() {
    scanf("%d %d", &in_m, &in_n);
    sieve();
    for (int i = in_m; i <= in_n; ++i)
        if (prime_table[i])
            printf("%d\n", i);
    return 0;
}
