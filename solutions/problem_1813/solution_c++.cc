/*
 * Baekjoon Online Judge #1813
 * https://www.acmicpc.net/problem/1813
 */

#include <bits/stdc++.h>

using namespace std;

int N, true_table[100001];

int main() {
    scanf("%d", &N);
    memset(true_table, 0, sizeof true_table);
    int max_val = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        scanf("%d", &a);
        true_table[a]++;
        max_val = max(max_val, a);
    }
    for (int i = max_val; i >= 0; --i) {
        if (true_table[i] == i) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
