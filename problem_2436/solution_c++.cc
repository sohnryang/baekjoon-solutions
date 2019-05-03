/*
 * Baekjoon Online Judge #2436
 * https://www.acmicpc.net/problem/2436
 */

#include <bits/stdc++.h>

using namespace std;

int A, B;

pair<int, int> solve() {
    assert(B % A == 0);
    int ab = B / A;
    pair<int, int> result;
    for (int a = 1; a <= (int)sqrt(ab); ++a) {
        if (ab % a != 0) continue;
        int b = ab / a;
        if (__gcd(a, b) != 1) continue;
        result.first = a * A;
        result.second = b * A;
    }
    return result;
}

int main() {
    scanf("%d %d", &A, &B);
    auto result = solve();
    printf("%d %d\n", result.first, result.second);
    return 0;
}
