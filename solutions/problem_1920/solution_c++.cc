/*
 * Baekjoon Online Judge #1920
 * https://www.acmicpc.net/problem/1920
 */

#include <bits/stdc++.h>

using namespace std;

int N, A[100001], M;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
    sort(A, A + N);
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int n;
        scanf("%d", &n);
        printf("%d\n", binary_search(A, A + N, n) ? 1 : 0);
    }
    return 0;
}
