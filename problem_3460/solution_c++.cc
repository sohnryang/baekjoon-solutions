/*
 * Baekjoon Online Judge #3460
 * https://www.acmicpc.net/problem/3460
 */

#include <cstdio>

using namespace std;

unsigned int in_t, in_n;

int main() {
    scanf("%d", &in_t);
    for (int i = 0; i < in_t; ++i) {
        scanf("%d", &in_n);
        int current = 0;
        while (in_n != 0) {
            if (in_n % 2 == 1)
                printf("%d ", current);
            current++;
            in_n = in_n >> 1;
        }
        printf("\n");
    }
    return 0;
}
