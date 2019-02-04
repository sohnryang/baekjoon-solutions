/*
 * Baekjoon Online Judge #1977
 * https://www.acmicpc.net/problem/1977
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int in_m, in_n;
    scanf("%d", &in_m);
    scanf("%d", &in_n);
    int max_sq = floor(sqrt(in_n)), min_sq = ceil(sqrt(in_m)), result = 0;
    if (max_sq >= min_sq) {
        for (int i = min_sq; i <= max_sq; ++i)
            result += i * i;
        printf("%d\n", result);
        printf("%d\n", min_sq * min_sq);
    } else {
        printf("-1\n");
    }
    return 0;
}
