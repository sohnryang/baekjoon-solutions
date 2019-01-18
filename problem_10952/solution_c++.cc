/*
 * Baekjoon Online Judge #10952
 * https://www.acmicpc.net/problem/10952
 */

#include <bits/stdc++.h>

using namespace std;

int in_a, in_b;

int main() {
    while (true) {
        scanf("%d %d", &in_a, &in_b);
        if (in_a == 0 && in_b == 0) break;
        printf("%d\n", in_a + in_b);
    }
    return 0;
}
