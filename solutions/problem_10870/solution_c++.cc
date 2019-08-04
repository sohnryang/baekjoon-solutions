/*
 * Baekjoon Online Judge #10870
 * https://www.acmicpc.net/problem/10870
 */

#include <cstdio>
#include <cstring>

using namespace std;

int cache[50];

int fib(int n) {
    int &ret = cache[n];
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (ret != -1) return ret;
    ret = fib(n - 1) + fib(n - 2);
    return ret;
}

int main() {
    int N;
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    printf("%d\n", fib(N));
    return 0;
}
