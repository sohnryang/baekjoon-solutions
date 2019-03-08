/*
 * Baekjoon Online Judge #1009
 * https://www.acmicpc.net/problem/1009
 */

#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int A, B;
        scanf("%d %d", &A, &B);
        A %= 10;
        int result = 1;
        for (int j = 0; j < B; ++j) {
            result *= A;
            result %= 10;
        }
        printf("%d\n", result == 0 ? 10 : result);
    }
    return 0;
}
