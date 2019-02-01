/*
 * Baekjoon Online Judge #2884
 * https://www.acmicpc.net/problem/2884
 */

#include <bits/stdc++.h>

using namespace std;

int in_h, in_m;

int main() {
    scanf("%d %d", &in_h, &in_m);
    int abstime = in_h * 60 + in_m;
    int alarmtime = (abstime - 45 + 60 * 24) % (60 * 24);
    printf("%d %d\n", alarmtime / 60, alarmtime % 60);
    return 0;
}
