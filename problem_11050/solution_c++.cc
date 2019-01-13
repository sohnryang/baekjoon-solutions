/*
 * Baekjoon Online Judge #11050
 * https://www.acmicpc.net/problem/11050
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_k;

int bino(int n, int k) {
    if (n == k || k == 0) return 1;
    else return bino(n - 1, k - 1) + bino(n - 1, k);
}

int main() {
    scanf("%d %d", &in_n, &in_k);
    printf("%d\n", bino(in_n, in_k));
    return 0;
}
