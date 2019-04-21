#include <bits/stdc++.h>

using namespace std;

int R, C;
char B[21][21];

const int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

inline bool in_range(int y, int x) {
    return y >= 0 && y < R && x >= 0 && x < C;
}

int solve(int y, int x, unsigned long used) {
    if (!in_range(y, x)) return 0;
    bitset<26> used_b(used);
    if (used_b[B[y][x] - 'A'] == 1) return 0;
    used_b[B[y][x] - 'A'] = 1;
    unsigned long newused = used_b.to_ulong();
    int result = 0;
    for (int i = 0; i < 4; ++i)
        result = max(result, solve(y + dy[i], x + dx[i], newused));
    return result + 1;
}

int main() {
    scanf("%d %d", &R, &C);
    for (int y = 0; y < R; ++y)
        for (int x = 0; x < C; ++x)
            scanf(" %c", &B[y][x]);
    unsigned long used = 0;
    printf("%d\n", solve(0, 0, used));
    return 0;
}
