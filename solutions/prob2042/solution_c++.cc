/*
 * Baekjoon Online Judge #2042
 * https://www.acmicpc.net/problem/2042
 */

#include <cstdio>
#include <vector>

using namespace std;

class FenwickTree {
private:
    vector<long long> tree;
public:
    FenwickTree(int n) : tree(n + 1) {}

    long long sum(int pos) {
        ++pos;
        long long ret = 0;
        while (pos > 0) {
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    void add(int pos, long long val) {
        ++pos;
        while (pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    FenwickTree ft(N);
    vector<int> arr;
    for (int i = 0; i < N; ++i) {
        int n;
        scanf("%d", &n);
        ft.add(i, n);
        arr.push_back(n);
    }
    for (int i = 0; i < M + K; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            ft.add(b - 1, -arr[b - 1] + c);
            arr[b - 1] = c;
        }
        else printf("%lld\n", ft.sum(c - 1) - ft.sum(b - 2));
    }
    return 0;
}
