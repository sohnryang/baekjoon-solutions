/*
 * Baekjoon Online Judge #1975
 * https://www.acmicpc.net/problem/1975
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int result = 0;
        for (int i = 2; i <= N; ++i) {
            int n = N;
            while (n % i == 0) {
                result++;
                n /= i;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
