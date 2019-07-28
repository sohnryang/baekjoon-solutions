/*
 * Baekjoon Online Judge #2750
 * https://www.acmicpc.net/problem/2750
 */

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int in_n;
vector<int> in_arr;

int main() {
    scanf("%d", &in_n);
    for (int i = 0; i < in_n; ++i) {
        int input;
        scanf("%d", &input);
        in_arr.push_back(input);
    }

    sort(in_arr.begin(), in_arr.end());
    for (int i = 0; i < in_n; ++i)
        printf("%d\n", in_arr[i]);
    return 0;
}
