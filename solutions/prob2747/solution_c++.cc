/*
 * Baekjoon Online Judge #2747
 * https://www.acmicpc.net/problem/2747
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
    int input_n;
    memset(cache, -1, sizeof(cache));
    scanf("%d", &input_n);
    printf("%d\n", fib(input_n));
    return 0;
}
