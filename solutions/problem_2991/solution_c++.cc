/*
 * Baekjoon Online Judge #2991
 * https://www.acmicpc.net/problem/2991
 */

#include <bits/stdc++.h>

using namespace std;

int in_a, in_b, in_c, in_d, in_p, in_m, in_n;

int main() {
    scanf("%d %d %d %d", &in_a, &in_b, &in_c, &in_d);
    scanf("%d %d %d", &in_p, &in_m, &in_n);
    int arr[] = {in_p, in_m, in_n};
    for (int i = 0; i < 3; ++i) {
        int a = arr[i] % (in_a + in_b), b = arr[i] % (in_c + in_d);
        a = !a ? in_a + in_b : a;
        b = !b ? in_c + in_d : b;
        printf("%d\n", (a <= in_a) + (b <= in_c));
    }
    return 0;
}
