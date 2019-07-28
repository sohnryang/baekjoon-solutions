/*
 * Baekjoon Online Judge #1932
 * https://acmicpc.net/problem/1932
 */

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int in_n, triangle[501][501], cache[501][501];

int path(int y, int x) {
	int &ret = cache[y][x];
	if (ret != -1) return ret + triangle[y][x];
	else if (y == in_n) return 0;

    ret = max(path(y + 1, x), path(y + 1, x + 1));
    return ret + triangle[y][x];
}

int main() {
    memset(triangle, -1, sizeof(triangle));
    memset(cache, -1, sizeof(cache));
    scanf("%d", &in_n);
    for (int y = 0; y < in_n; ++y)
        for (int x = 0; x <= y; ++x)
            scanf("%d", &triangle[y][x]);

    printf("%d\n", path(0, 0));
    return 0;
}
