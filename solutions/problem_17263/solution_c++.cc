/*
 * Baekjoon Online Judge #17263
 * https://www.acmicpc.net/problem/17263
 */

#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int result = 0;
    for (int i = 0; i < N; ++i) {
        int A;
        scanf("%d", &A);
        result = max(A, result);
    }
    printf("%d\n", result);
    return 0;
}
