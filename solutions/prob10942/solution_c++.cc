/*
 * Baekjoon Online Judge #10942
 * https://www.acmicpc.net/problem/10942
 */

#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 2001;
int N, M, num[MAX_N], dp[MAX_N][MAX_N];

int palindrome(int start, int end) {
    if (start == end) return 1;
    int &ret = dp[start][end];
    if (ret != -1) return ret;
    if (num[start] != num[end]) ret = 0;
    else if (end - start == 1) ret = 1;
    else ret = palindrome(start + 1, end - 1);
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &num[i]);
    scanf("%d", &M);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < M; ++i) {
        int S, E;
        scanf("%d %d", &S, &E);
        printf("%d\n", palindrome(S - 1, E - 1));
    }
    return 0;
}
