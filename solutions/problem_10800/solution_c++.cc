/*
 * Baekjoon Online Judge #10800
 * https://www.acmicpc.net/problem/10800
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 2001;
int N;
vector<pair<int, int>> B[MAX_SIZE];

int main() {
    scanf("%d", &N);
    int min_size = MAX_SIZE;
    for (int i = 0; i < N; ++i) {
        int c, s;
        scanf("%d %d", &c, &s);
        min_size = min(min_size, s);
        B[s].push_back(make_pair(i, c));
    }
    map<int, int> c_sum;
    int sum = 0;
    vector<int> result(N, 0);
    for (int s = 0; s < MAX_SIZE; ++s) {
        if (B[s].size() <= 0) continue;
        for (auto e: B[s]) {
            int i = e.first, c = e.second;
            result[i] = sum - c_sum[c];
        }
        for (auto e: B[s]) {
            int i = e.first, c = e.second;
            if (c_sum.count(c) < 1) c_sum[c] = s;
            else c_sum[c] += s;
            sum += s;
        }
    }
    for (auto r: result)
        printf("%d\n", r);
    return 0;
}
