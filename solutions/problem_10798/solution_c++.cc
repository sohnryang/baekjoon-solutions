/*
 * Baekjoon Online Judge #10798
 * https://www.acmicpc.net/problem/10798
 */

#include <bits/stdc++.h>

using namespace std;

char T[5][15];

int main() {
    memset(T, 0, sizeof T);
    for (int i = 0; i < 5; ++i)
        scanf("%s", T[i]);
    for (int j = 0; j < 15; ++j)
        for (int i = 0; i < 5; ++i)
            if (T[i][j] != 0)
                printf("%c", T[i][j]);
    printf("\n");
    return 0;
}
