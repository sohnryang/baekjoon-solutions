/*
 * Baekjoon Online Judge #2609
 * https://www.acmicpc.net/problem/2609
 */

#include <cstdio>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int in_a, in_b;
    scanf("%d %d", &in_a, &in_b);
    printf("%d\n%d\n", gcd(in_a, in_b), in_a * in_b / gcd(in_a, in_b));
    return 0;
}
