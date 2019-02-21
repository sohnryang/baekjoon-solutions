/*
 * Baekjoon Online Judge #16969
 * https://www.acmicpc.net/problem/16969
 */

#include <bits/stdc++.h>

using namespace std;

char in_format[1000001];
int len;
const unsigned long long MOD = 1000000009ull;

unsigned long long plates() {
    unsigned long long result = in_format[0] == 'd' ? 10ull : 26;
    for (int i = 1; i < len; ++i) {
        int available = in_format[i] == 'd' ? 10ull : 26ull;
        if (in_format[i] == in_format[i - 1])
            result = (result * (available - 1ull)) % MOD;
        else
            result = (result * available) % MOD;
    }
    return result;
}

int main() {
    scanf("%s", in_format);
    len = strlen(in_format);
    printf("%llu\n", plates());
}
