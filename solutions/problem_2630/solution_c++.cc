/*
 * Baekjoon Online Judge #2630
 * https://www.acmicpc.net/problem/2630
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_paper[130][130];

int count_0(int y, int x, int size) {
    if (size == 1) return in_paper[y][x] == 0;
    bool all_0 = true;
    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (in_paper[i][j] != 0) {
                all_0 = false;
                break;
            }
        }
    }
    if (all_0) return 1;
    int result = 0;
    result += count_0(y, x, size / 2);
    result += count_0(y + size / 2, x, size / 2);
    result += count_0(y, x + size / 2, size / 2);
    result += count_0(y + size / 2, x + size / 2, size / 2);
    return result;
}

int count_1(int y, int x, int size) {
    if (size == 1) return in_paper[y][x] == 1;
    bool all_1 = true;
    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (in_paper[i][j] != 1) {
                all_1 = false;
                break;
            }
        }
    }
    if (all_1) return 1;
    int result = 0;
    result += count_1(y, x, size / 2);
    result += count_1(y + size / 2, x, size / 2);
    result += count_1(y, x + size / 2, size / 2);
    result += count_1(y + size / 2, x + size / 2, size / 2);
    return result;
}

int main() {
    memset(in_paper, 0, sizeof in_paper);
    scanf("%d", &in_n);
    for (int y = 0; y < in_n; ++y)
        for (int x = 0; x < in_n; ++x)
            scanf("%d", &in_paper[y][x]);
    printf("%d\n%d\n", count_0(0, 0, in_n), count_1(0, 0, in_n));
    return 0;
}
