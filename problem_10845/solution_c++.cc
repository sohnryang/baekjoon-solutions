/*
 * Baekjoon Online Judge #10845
 * https://www.acmicpc.net/problem/10845
 */

#include <bits/stdc++.h>

using namespace std;

int in_n;

int main() {
    scanf("%d", &in_n);
    queue<int> q;
    while (in_n--) {
        char raw_str[10];
        scanf("%s", raw_str);
        if (strcmp(raw_str, "push") == 0) {
            int in_val;
            scanf("%d", &in_val);
            q.push(in_val);
        } else if (strcmp(raw_str, "pop") == 0) {
            if (q.empty())
                printf("-1");
            else {
                printf("%d", q.front());
                q.pop();
            }
            printf("\n");
        } else if (strcmp(raw_str, "size") == 0) {
            printf("%d\n", q.size());
        } else if (strcmp(raw_str, "empty") == 0) {
            printf("%d\n", q.empty());
        } else if (strcmp(raw_str, "front") == 0) {
            if (q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.front());
        } else if (strcmp(raw_str, "back") == 0) {
            if (q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.back());
        } else {
            fprintf(stderr, "***error***\n");
            assert(false);
        }
    }
    return 0;
}
