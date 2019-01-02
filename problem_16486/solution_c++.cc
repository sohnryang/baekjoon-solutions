/*
 * Baekjoon Online Judge #16486
 * https://www.acmicpc.net/problem/16486
 */

#include <cstdio>

using namespace std;

const double PI = 3.141592;

int main() {
    double in_d1, in_d2;
    scanf("%lf", &in_d1);
    scanf("%lf", &in_d2);
    printf("%f\n", in_d1 * 2 + 2 * PI * in_d2);
    return 0;
}
