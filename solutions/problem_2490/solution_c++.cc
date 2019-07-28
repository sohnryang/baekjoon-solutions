/*
 * Baekjoon Online Judge #2490
 * https://www.acmicpc.net/problem/2490
 */

#include <cstdio>

int main() {
    int in[4];
    for (int i = 0; i < 3; ++i) {
        scanf("%d %d %d %d", &in[0], &in[1], &in[2], &in[3]);
        int backs = 0;
        for (int j = 0; j < 4; ++j)
            backs += in[j];
        if (backs == 3) printf("A\n");
        else if (backs == 2) printf("B\n");
        else if (backs == 1) printf("C\n");
        else if (backs == 0) printf("D\n");
        else printf("E\n");
    }
    return 0;
}
