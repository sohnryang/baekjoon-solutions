/*
 * Baekjoon Online Judge #15353
 * https://www.acmicpc.net/problem/15353
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> in_reva, in_revb;

int main() {
    char a[10001], b[10001];
    scanf("%s %s", a, b);
    for (int i = strlen(a) - 1; i >= 0; --i)
        in_reva.push_back(a[i] - '0');
    for (int i = strlen(b) - 1; i >= 0; --i)
        in_revb.push_back(b[i] - '0');
    int len_a = strlen(a), len_b = strlen(b);
    int min_len = min(len_a, len_b);
    int max_len = max(len_a, len_b);
    vector<int> result;
    for (int i = 0; i < min_len; ++i)
        result.push_back(in_reva[i] + in_revb[i]);
    for (int i = min_len; i < max_len; ++i) {
        int aval = i >= len_a ? 0 : in_reva[i];
        int bval = i >= len_b ? 0 : in_revb[i];
        result.push_back(aval + bval);
    }
    result.push_back(0);
    for (int i = 1; i < max_len; ++i) {
        result[i] += (result[i - 1] / 10);
        result[i - 1] %= 10;
    }
    reverse(result.begin(), result.end());
    for (int i = 0; i < max_len + 1; ++i)
        if (!(i == 0 && result[i] == 0))
            printf("%d", result[i]);
    printf("\n");
    return 0;
}
