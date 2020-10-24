/*
 * Baekjoon Online Judge #1717
 */

#include <bits/stdc++.h>

using namespace std;

class UFDS {
private:
    vector<int> p, r, sz;
    int num_sets;
public:
    UFDS(int N) {
        p.assign(N, 0);
        sz.assign(N, 1);
        r.assign(N, 0);
        num_sets = N;
        for (int i = 0; i < N; ++i) p[i] = i;
    }
    int find_set(int i) {
        return (p[i] == i) ? i : (p[i] = find_set(p[i]));
    }
    bool same(int i, int j) {
        return find_set(i) == find_set(j);
    }
    void union_set(int i, int j) {
        if (!same(i, j)) {
            num_sets--;
            int x = find_set(i), y = find_set(j);
            if (r[x] > r[y]) {
                p[y] = x;
                sz[x] += sz[y];
            } else {
                p[x] = y;
                sz[y] += sz[x];
                if (r[x] == r[y]) r[y]++;
            }
        }
    }
    int cnt() {
        return num_sets;
    }
    int size(int i) {
        return sz[find_set(i)];
    }
};

int N, M;

int main() {
    scanf("%d %d", &N, &M);
    UFDS ufds(N + 1);
    for (int i = 0; i < M; ++i) {
        int cmd, a, b;
        scanf("%d %d %d", &cmd, &a, &b);
        if (cmd == 0) ufds.union_set(a, b);
        else printf("%s\n", ufds.same(a, b) ? "YES": "NO");
    }
    return 0;
}
