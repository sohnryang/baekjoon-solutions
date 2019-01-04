/*
 * Baekjoon Online Judge #1934
 * https://www.acmicpc.net/problem/1934
 */

#include <cstdio>

using namespace std;

int in_t, in_a, in_b;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    scanf("%d", &in_t);
    for (int i = 0; i < in_t; ++i) {
        scanf("%d %d", &in_a, &in_b);
        printf("%d\n", in_a * in_b / gcd(in_a, in_b));
    }
    return 0;
}
