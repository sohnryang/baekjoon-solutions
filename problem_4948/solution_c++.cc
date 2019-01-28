/*
 * Baekjoon Online Judge #4948
 * https://www.acmicpc.net/problem/4948
 */

#include <bits/stdc++.h>

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

int bertrand(int n) {
    int result = 0;
    for (int i = n + 1; i <= 2 * n; ++i)
        result += prime_table[i];
    return result;
}

int main() {
    int in_n;
    sieve();
    scanf("%d", &in_n);
    while (in_n != 0) {
        printf("%d\n", bertrand(in_n));
        scanf("%d", &in_n);
    }
    return 0;
}
