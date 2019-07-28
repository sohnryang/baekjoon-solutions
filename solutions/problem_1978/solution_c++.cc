/*
 * Baekjoon Online Judge #1978
 * https://www.acmicpc.net/problem/1978
 */

#include <cstdio>
#include <cmath>

using namespace std;

int in_n, in_numbers[101];

bool test_prime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    int cnt = sqrt(n);
    bool result = true;
    for (int i = 2; i <= cnt && result; ++i)
        if (n % i == 0) result = false;
    return result;
}

int main() {
    scanf("%d", &in_n);
    int result = 0;
    for (int i = 0; i < in_n; ++i) {
        int n;
        scanf("%d", &n);
        result += test_prime(n) ? 1 : 0;
    }
    printf("%d\n", result);
    return 0;
}
