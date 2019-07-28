/*
 * Baekjoon Online Judge #2581
 * https://www.acmicpc.net/problem/2581
 */

#include <cstdio>
#include <cmath>

using namespace std;

int in_m, in_n;

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
    scanf("%d", &in_m);
    scanf("%d", &in_n);
    int sum = 0, minimum = 0;
    for (int i = in_m; i <= in_n; ++i) {
        bool prime = test_prime(i);
        sum += prime ? i : 0;
        minimum = prime && minimum == 0 ? i : minimum;
    }
    if (sum == 0) printf("-1\n");
    else printf("%d\n%d\n", sum, minimum);
    return 0;
}
