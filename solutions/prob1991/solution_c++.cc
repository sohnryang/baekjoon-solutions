/*
 * Baekjoon Online Judge #1991
 * https://www.acmicpc.net/problem/1991
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, left_nodes[27], right_nodes[27];

void preorder(int root) {
    printf("%c", root + 'A');
    if (left_nodes[root] != -1) preorder(left_nodes[root]);
    if (right_nodes[root] != -1) preorder(right_nodes[root]);
}

void inorder(int root) {
    if (left_nodes[root] != -1) inorder(left_nodes[root]);
    printf("%c", root + 'A');
    if (right_nodes[root] != -1) inorder(right_nodes[root]);
}

void postorder(int root) {
    if (left_nodes[root] != -1) postorder(left_nodes[root]);
    if (right_nodes[root] != -1) postorder(right_nodes[root]);
    printf("%c", root + 'A');
}

int main() {
    scanf("%d", &in_n);
    memset(left_nodes, -1, sizeof(left_nodes));
    memset(right_nodes, -1, sizeof(right_nodes));
    for (int i = 0; i < in_n; ++i) {
        char in_1, in_2, in_3;
        scanf(" %c %c %c", &in_1, &in_2, &in_3);
        if (in_2 != '.') left_nodes[in_1 - 'A'] = in_2 - 'A';
        if (in_3 != '.') right_nodes[in_1 - 'A'] = in_3 - 'A';
    }
    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    printf("\n");
    return 0;
}
