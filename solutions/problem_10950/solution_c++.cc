/*
 * Baekjoon Online Judge #10950
 * https://www.acmicpc.net/problem/10950
 */

#include <cstdio>

using namespace std;

int in_t, in_a, in_b;

int main() {
    scanf("%d", &in_t);
    for (int i = 0; i < in_t; ++i) {
        scanf("%d %d", &in_a, &in_b);
        printf("%d\n", in_a + in_b);
    }
    return 0;
}