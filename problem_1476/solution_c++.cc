/*
 * Baekjoon Online Judge #1476
 * https://www.acmicpc.net/problem/1476
 */

#include <bits/stdc++.h>

using namespace std;

int in_e, in_s, in_m;

int main() {
    scanf("%d %d %d", &in_e, &in_s, &in_m);
    int year = 1, curr_e = 1, curr_s = 1, curr_m = 1;
    while (curr_e != in_e || curr_s != in_s || curr_m != in_m) {
        year++;
        curr_e++;
        curr_s++;
        curr_m++;
        curr_e = (curr_e - 1) % 15 + 1;
        curr_s = (curr_s - 1) % 28 + 1;
        curr_m = (curr_m - 1) % 19 + 1;
    }
    printf("%d\n", year);
    return 0;
}
