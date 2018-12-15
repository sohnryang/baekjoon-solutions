/*
 * Baekjoon Online Judge #11052
 * https://www.acmicpc.net/problem/11052
 */

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int in_n, in_cards[1002], dp[1002];

int buy(int n) {
    int &ret = dp[n];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 1; i <= n; ++i)
        ret = max(ret, buy(n - i) + in_cards[i]);
    return ret;
}

int main() {
    scanf("%d", &in_n);
    memset(in_cards, -1, sizeof(in_cards));
    memset(dp, -1, sizeof(dp));
    in_cards[0] = dp[0] = 0;
    for (int i = 1; i <= in_n; ++i)
        scanf("%d", &in_cards[i]);
    printf("%d\n", buy(in_n));
}
