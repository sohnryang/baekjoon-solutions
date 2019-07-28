/*
 * Baekjoon Online Judge #9012
 * https://www.acmicpc.net/problem/9012
 */

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int in_t;

int main() {
    scanf("%d", &in_t);
    for (int i = 0; i < in_t; ++i) {
        char str[51];
        scanf("%s", str);
        int len = strlen(str);
        stack<char> brackets;
        bool vps = true;
        for (int j = 0; j < len; ++j) {
            if (str[j] == '(') brackets.push(str[j]);
            else {
                if (brackets.size() == 0) {
                    vps = false;
                    break;
                } else
                    brackets.pop();
            }
        }
        vps = vps && brackets.size() == 0;
        if (vps) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
