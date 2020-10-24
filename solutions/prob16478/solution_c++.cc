/*
 * Baekjoon Online Judge #16478
 * https://www.acmicpc.net/problem/16478
 */

#include <cstdio>

using namespace std;

int main() {
    double in_p_ab, in_p_bc, in_p_cd;
    scanf("%lf %lf %lf", &in_p_ab, &in_p_bc, &in_p_cd);
    printf("%f\n", in_p_ab * in_p_cd / in_p_bc);
    return 0;
}
