/*
 * Baekjoon Online Judge #15688
 * https://www.acmicpc.net/problem/15688
 */

#include <bits/stdc++.h>

using namespace std;

int in_n;

int main() {
    scanf("%d", &in_n);
    vector<int> in_numbers;
    for (int i = 0; i < in_n; ++i) {
        int in_num;
        scanf("%d", &in_num);
        in_numbers.push_back(in_num);
    }
    sort(in_numbers.begin(), in_numbers.end());
    for (int i = 0; i < in_n; ++i)
        printf("%d\n", in_numbers[i]);
    return 0;
}
