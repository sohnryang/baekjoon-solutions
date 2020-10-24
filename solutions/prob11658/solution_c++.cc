/*
 * Baekjoon Online Judge #11658
 * https://www.acmicpc.net/problem/11658
 */

#include <cstdio>
#include <vector>

using namespace std;

class FenwickTree2D {
private:
    vector<vector<int>> tree;
public:
    FenwickTree2D(int r, int c): tree(r, vector<int>(c)) {}
    
    void add(int r, int c, int val) {
        for (int i = r; i < tree.size(); i |= i + 1)
            for (int j = c; j < tree[i].size(); j |= j + 1)
                tree[i][j] += val;
    }

    int sum(int r, int c) {
        int ret = 0;
        for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = c; j >= 0; j = (j & (j + 1)) - 1)
                ret += tree[i][j];
        return ret;
    }

    int sum(int r1, int c1, int r2, int c2) {
        return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + \
               sum(r1 - 1, c1 - 1);
    }
};

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    FenwickTree2D ft(N, N);
    vector<vector<int>> mat;

    for (int x = 0; x < N; ++x) {
        vector<int> line;
        for (int y = 0; y < N; ++y) {
            int n;
            scanf("%d", &n);
            line.push_back(n);
            ft.add(x, y, n);
        }
        mat.push_back(line);
    }

    for (int _ = 0; _ < M; ++_) {
        int w;
        scanf("%d", &w);
        if (w == 0) {
            int x, y, c;
            scanf("%d %d %d", &x, &y, &c);
            x -= 1;
            y -= 1;
            ft.add(x, y, c - mat[x][y]);
            mat[x][y] = c;
        } else {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            x1 -= 1;
            y1 -= 1;
            x2 -= 1;
            y2 -= 1;
            printf("%d\n", ft.sum(x1, y1, x2, y2));
        }
    }

    return 0;
}
