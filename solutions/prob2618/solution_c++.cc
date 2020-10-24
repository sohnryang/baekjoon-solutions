/*
 * Baekjoon Online Judge #2618
 * https://www.acmicpc.net/problem/2618
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

const int MAX_N = 1010;
int N, W, dp[MAX_N][MAX_N], choice[MAX_N][MAX_N];
pair<int, int> pos[MAX_N];
vector<int> choice_list;

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int policecar(int a, int b) {
    if (max(a, b) == W) return 0;
    int &ret = dp[a][b];
    if (ret != -1) return ret;
    auto source_a = a == 0 ? make_pair(1, 1) : pos[a];
    auto source_b = b == 0 ? make_pair(N, N) : pos[b];
    int dest_idx = max(a, b) + 1;
    auto dest = pos[dest_idx];
    int choice_a = dist(source_a, dest) + policecar(dest_idx, b);
    int choice_b = dist(source_b, dest) + policecar(a, dest_idx);
    ret = min(choice_a, choice_b);
    choice[a][b] = choice_a < choice_b ? 1 : 2;
    return ret;
}

void trace() {
    int a = 0, b = 0;
    while (max(a, b) < W) {
        choice_list.push_back(choice[a][b]);
        if (choice[a][b] == 1) a = max(a, b) + 1;
        else b = max(a, b) + 1;
    }
}

int main() {
    scanf("%d %d", &N, &W);
    memset(dp, -1, sizeof(dp));
    memset(choice, 0, sizeof(choice));
    for (int i = 1; i <= W; ++i) {
        int y, x;
        scanf("%d %d", &y, &x);
        pos[i] = make_pair(y, x);
    }
    printf("%d\n", policecar(0, 0));
    trace();
    for (int choice: choice_list) printf("%d\n", choice);
    return 0;
}
