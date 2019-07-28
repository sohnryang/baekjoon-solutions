/*
 * Baekjoon Online Judge #1149
 * https://www.acmicpc.net/problem/1149
 */

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int in_n;
int cost[1001][3];
int cache[1001][1001];

int paint_cost(int last, int nth) {
    int &ret = cache[last][nth];
    if (ret != -1) return ret;
    if (nth == in_n) {
        ret = 0;
        return ret;
    } else {
        ret = paint_cost((last + 1) % 3, nth + 1)
            + cost[nth][(last + 1) % 3];
        ret = min(ret, paint_cost((last + 2) % 3, nth + 1)
                       + cost[nth][(last + 2) % 3]);
        return ret;
    }
}

int main() {
    scanf("%d", &in_n);
    memset(cost, -1, sizeof(cost));
    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < in_n; ++i)
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);

    printf("%d\n", min(paint_cost(0, 0), paint_cost(1, 0)));
    return 0;
}
