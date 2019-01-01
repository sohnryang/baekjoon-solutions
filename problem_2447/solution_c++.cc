/*
 * Baekjoon Online Judge #2447
 * https://www.acmicpc.net/problem/2447
 */

#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int stars[6562][6562];

void draw_stars(int y, int x, int size) {
    if (size == 1) {
        stars[y][x] = 1;
        return;
    }
    draw_stars(y, x, size / 3);
    draw_stars(y + size / 3, x, size / 3);
    draw_stars(y + size / 3 * 2, x, size / 3);
    draw_stars(y, x + size / 3, size / 3);
    draw_stars(y + size / 3 * 2, x + size / 3, size / 3);
    draw_stars(y, x + size / 3 * 2, size / 3);
    draw_stars(y + size / 3, x + size / 3 * 2, size / 3);
    draw_stars(y + size / 3 * 2, x + size / 3 * 2, size / 3);
}

void print_stars(int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            printf("%c", stars[i][j] == 1 ? '*': ' ');
        printf("\n");
    }
}

int main() {
    int in_n;
    scanf("%d", &in_n);
    memset(stars, 0, sizeof(stars));
    draw_stars(0, 0, in_n);
    print_stars(in_n);
    return 0;
}
