/*
 * Baekjoon Online Judge #16479
 * https://www.acmicpc.net/problem/16479
 */

#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    double in_k, in_d1, in_d2;
    scanf("%lf", &in_k);
    scanf("%lf %lf", &in_d1, &in_d2);
    double squared_h = pow(in_k, 2) - pow((in_d1 - in_d2) / 2, 2);
    printf("%f", squared_h);
    return 0;
}
