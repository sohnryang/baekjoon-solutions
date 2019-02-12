/*
 * Baekjoon Online Judge #10989
 * https://www.acmicpc.net/problem/10989
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10001;
int in_n, in_numstats[MAX];

int main() {
    memset(in_numstats, 0, sizeof(in_numstats));
    scanf("%d", &in_n);
    for (int i = 0; i < in_n; ++i) {
        int in;
        scanf("%d", &in);
        in_numstats[in]++;
    }
    for (int i = 1; i < MAX; ++i)
        for (int j = 0; j < in_numstats[i]; ++j)
            printf("%d\n", i);
    return 0;
}
