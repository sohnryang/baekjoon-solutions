/*
 * Baekjoon Online Judge #9020
 * https://www.acmicpc.net/problem/9020
 */

#include <bits/stdc++.h>

using namespace std;

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

pair<int, int> goldbach(int n) {
    pair<int, int> result = make_pair(0, 0);
    int smaller = -1;
    for (int i = 1; i <= n / 2; ++i)
        if (prime_table[i] && prime_table[n - i])
            smaller = i;
    result.first = smaller;
    result.second = n - smaller;
    return result;
}

int main() {
    int in_t;
    sieve();
    scanf("%d", &in_t);
    for (int i = 0; i < in_t; ++i) {
        int in_n;
        scanf("%d", &in_n);
        pair<int, int> result = goldbach(in_n);
        printf("%d %d\n", result.first, result.second);
    }
    return 0;
}
