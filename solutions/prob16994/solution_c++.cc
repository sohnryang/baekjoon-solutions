/*
 * Baekjoon Online Judge #16994
 * https://www.acmicpc.net/problem/16994
 */

#include <cstdio>
#include <cstring>
#include <ext/rope>
#include <string>

using namespace std;
using namespace __gnu_cxx;

const int MAX_LEN = 100001;

int main() {
    crope rp;
    char rawstr[MAX_LEN];
    scanf("%s", rawstr);
    rp.append(rawstr);
    int len = strlen(rawstr);
    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; ++i) {
        int q;
        scanf("%d", &q);
        if (q == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            rp = rp.substr(x, y - x + 1) + rp.substr(0, x) + \
                 rp.substr(y + 1, len);
        } else if (q == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            rp = rp.substr(0, x) + rp.substr(y + 1, len) + \
                 rp.substr(x, y - x + 1);
        } else {
            int x;
            scanf("%d", &x);
            printf("%c\n", rp.at(x));
        }
    }

    return 0;
}
