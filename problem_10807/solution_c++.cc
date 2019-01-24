/*
 * Baekjoon Online Judge #10807
 * https://www.acmicpc.net/problem/10807
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_numbers[101], in_v;

int main() {
    scanf("%d", &in_n);
    for (int i = 0; i < in_n; ++i)
        scanf("%d", &in_numbers[i]);
    scanf("%d", &in_v);
    int result = 0;
    for (int i = 0; i < in_n; ++i)
        result += in_numbers[i] == in_v;
    printf("%d\n", result);
    return 0;
}
