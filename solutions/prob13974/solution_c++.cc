/*
 * Baekjoon Online Judge #13974
 * https://www.acmicpc.net/problem/13974
 */

#include <cstdio>
#include <cstring>

using namespace std;

int T, K, size[5001], s[5001], dp[5001][5001], C[5001][5001];
const int INF = 987654321;

void reset() {
    memset(size, 0, sizeof size);
    memset(s, 0, sizeof s);
    memset(dp, 0, sizeof dp);
    memset(C, 0, sizeof C);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &K);
        for (int i = 1; i <= K; ++i) {
            scanf("%d", &size[i]);
            s[i] = s[i - 1] + size[i];
        }
        for (int i = 1; i <= K; ++i) {
            dp[i - 1][i] = 0;
            C[i - 1][i] = i;
        }

        for (int m = 2; m <= K; ++m) {
            for (int i = 0; m + i <= K; ++i) {
                int j = i + m;
                dp[i][j] = INF;
                for (int k = C[i][j - 1]; k <= C[i + 1][j]; ++k) {
                    int curr = dp[i][k] + dp[k][j] + s[j] - s[i];
                    if (dp[i][j] > curr) {
                        dp[i][j] = curr;
                        C[i][j] = k;
                    }
                }
            }
        }
        printf("%d\n", dp[0][K]);
    }
    return 0;
}
