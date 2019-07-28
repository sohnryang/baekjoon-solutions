/*
 * Baekjoon Online Judge #11066
 * https://www.acmicpc.net/problem/11066
 */

#include <bits/stdc++.h>

using namespace std;

int in_t, in_k, in_size[501], dp[501][501], sum[501];
const int INF = numeric_limits<int>::max();

void init() {
    memset(in_size, -1, sizeof(in_size));
    memset(dp, -1, sizeof(dp));
    memset(sum, 0, sizeof(sum));
}

int merge(int left, int right) {
    if (right - left == 0) return 0;
    if (right - left == 1) return in_size[left] + in_size[left + 1];
    int &ret = dp[left][right];
    if (ret != -1) return ret;
    ret = INF;
    for (int mid = left; mid < right; ++mid)
        ret = min(
            ret,
            merge(left, mid) +
            merge(mid + 1, right) + sum[right] - sum[left - 1]
        );
    return ret;
}

int main() {
    scanf("%d", &in_t);
    while (in_t--) {
        scanf("%d", &in_k);
        init();
        for (int i = 0; i < in_k; ++i) {
            scanf("%d", &in_size[i]);
            sum[i] = i == 0 ? in_size[i] : sum[i - 1] + in_size[i];
        }
        printf("%d\n", merge(0, in_k - 1));
    }
    return 0;
}
