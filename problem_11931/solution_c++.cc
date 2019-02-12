/*
 * Baekjoon Online Judge #11931
 * https://www.acmicpc.net/problem/11931
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000002, OFFSET = 1000000;
int in_n, in_numstats[MAX];

int main() {
    memset(in_numstats, 0, sizeof(in_numstats));
    scanf("%d", &in_n);
    for (int i = 0; i < in_n; ++i) {
        int in;
        scanf("%d", &in);
        in_numstats[in + OFFSET]++;
    }
    for (int i = MAX - 1; i >= 0; --i)
        for (int j = 0; j < in_numstats[i]; ++j)
            printf("%d\n", i - OFFSET);
    return 0;
}
