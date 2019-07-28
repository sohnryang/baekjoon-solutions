/*
 * Baekjoon Online Judge #16961
 * https://www.acmicpc.net/problem/16961
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, visitors[2][367], results[5];

int main() {
    scanf("%d", &in_n);
    memset(visitors, 0, sizeof(visitors));
    memset(results, 0, sizeof(results));
    for (int i = 0; i < in_n; ++i) {
        char type;
        int start_date, end_date;
        scanf(" %c %d %d", &type, &start_date, &end_date);
        int idx = type == 'T' ? 0 : 1;
        for (int j = start_date; j <= end_date; ++j)
            visitors[idx][j]++;
        results[4] = max(results[4], end_date - start_date + 1);
    }
    for (int i = 1; i <= 366; ++i) {
        int curr_visitors = visitors[0][i] + visitors[1][i];
        results[0] += (curr_visitors >= 1);
        results[1] = max(results[1], curr_visitors);
        if (visitors[0][i] == visitors[1][i] && curr_visitors > 0) {
            results[2]++;
            results[3] = max(results[3], curr_visitors);
        }
    }
    for (int i = 0; i < 5; ++i)
        printf("%d\n", results[i]);
    return 0;
}
