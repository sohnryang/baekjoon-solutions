/*
 * Baekjoon Online Judge #15814
 * https://www.acmicpc.net/problem/15814
 */

#include <bits/stdc++.h>

using namespace std;

char S[101];
int T;

void swap(int a, int b) {
    char tmp = S[a];
    S[a] = S[b];
    S[b] = tmp;
}

int main() {
    scanf("%s", S);
    scanf("%d", &T);
    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);
        swap(A, B);
    }
    printf("%s\n", S);
    return 0;
}
