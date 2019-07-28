/*
 * Baekjoon Online Judge #1673
 * https://www.acmicpc.net/problem/1673
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_k;

int chicken(int coupons, int stamps) {
    coupons += stamps / in_k;
    stamps %= in_k;
    if (coupons <= 0) return 0;
    else return coupons + chicken(0, stamps + coupons);
}

int main() {
    while (scanf("%d %d", &in_n, &in_k) != -1)
        printf("%d\n", chicken(in_n, 0));
    return 0;
}
