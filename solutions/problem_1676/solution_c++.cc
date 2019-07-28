/*
 * Baekjoon Online Judge #1676
 * https://www.acmicpc.net/problem/1676
 */

#include <bits/stdc++.h>

using namespace std;

int N, d2 = 0, d5 = 0;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        int n = i;
        while (n % 2 == 0 || n % 5 == 0) {
            if (n % 2 == 0) d2++, n /= 2;
            if (n % 5 == 0) d5++, n /= 5;
        }
    }
    printf("%d\n", min(d2, d5));
    return 0;
}
