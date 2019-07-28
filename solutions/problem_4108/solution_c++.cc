/*
 * Baekjoon Online Judge #4108
 * https://www.acmicpc.net/problem/4108
 */

#include <bits/stdc++.h>

using namespace std;

int R, C;
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
char m[101][101];

inline bool in_range(int y, int x) {
    return y >= 0 && y < R && x >= 0 && x < C;
}

int main() {
    while (true) {
        scanf("%d %d", &R, &C);
        if (R == 0 && C == 0) break;
        for (int i = 0; i < R; ++i)
            scanf("%s", m[i]);
        for (int y = 0; y < R; ++y)
            for (int x = 0; x < C; ++x) {
                int result = 0;
                if (m[y][x] == '*') continue;
                for (int i = 0; i < 8; ++i) {
                    if (!in_range(y + dy[i], x + dx[i])) continue;
                    result += (m[y + dy[i]][x + dx[i]] == '*');
                }
                m[y][x] = '0' + result;
            }
        for (int i = 0; i < R; ++i)
            printf("%s\n", m[i]);
    }
    return 0;
}
