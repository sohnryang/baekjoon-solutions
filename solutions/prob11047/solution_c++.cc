/*
 * Baekjoon Online Judge #11047
 * https://www.acmicpc.net/problem/11047
 */

#include <bits/stdc++.h>

using namespace std;

int N, K, A[11];

int main() {
    scanf("%d %d", &N, &K);
    memset(A, 0, sizeof A);
    for (int i = N - 1; i >= 0; --i) scanf("%d", &A[i]);
    int result = 0;
    for (int i = 0; i < N && K > 0; ++i) {
        if (A[i] > K) continue;
        result += (K / A[i]);
        K %= A[i];
    }
    printf("%d\n", result);
    return 0;
}
