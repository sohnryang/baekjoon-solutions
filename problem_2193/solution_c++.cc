/*
 * Baekjoon Online Judge #2193
 * https://www.acmicpc.net/problem/2193
 */

#include <cstdio>
#include <cstring>

using namespace std;

long long cache[95];

long long fib(int n) {
    long long &ret = cache[n];
    if (n == 0) return 0ll;
    else if (n == 1) return 1ll;
    else if (ret != -1ll) return ret;
    ret = fib(n - 1) + fib(n - 2);
    return ret;
}

int main() {
    int input_n;
    memset(cache, -1, sizeof(cache));
    scanf("%d", &input_n);
    printf("%lli\n", fib(input_n));
    return 0;
}