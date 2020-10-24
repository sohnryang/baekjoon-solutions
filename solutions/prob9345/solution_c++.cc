/*
 * Baekjoon Online Judge #9345
 * https://www.acmicpc.net/problem/9345
 */

#include <algorithm>
#include <cstdio>
#include <numeric>
#include <vector>

using namespace std;

class RMQ {
private:
    vector<long long> tree;
    int len;

    long long init_tree(vector<long long>& arr, int lo, int hi, int node) {
        if (lo == hi) return tree[node] = arr[lo];
        int mid = (lo + hi) / 2;
        long long left = init_tree(arr, lo, mid, node * 2);
        long long right = init_tree(arr, mid + 1, hi, node * 2 + 1);
        return tree[node] = min(left, right);
    }

    long long query(int lo, int hi, int node, int node_lo, int node_hi) {
        if (hi < node_lo || node_hi < lo)
            return numeric_limits<long long>::max();
        if (lo <= node_lo && node_hi <= hi) return tree[node];
        int mid = (node_lo + node_hi) / 2;
        return min(query(lo, hi, node * 2, node_lo, mid),
                   query(lo, hi, node * 2 + 1, mid + 1, node_hi));
    }

    long long update(int idx, int newval, int node, int node_lo, int node_hi) {
        if (idx < node_lo || node_hi < idx) return tree[node];
        if (node_lo == node_hi) return tree[node] = newval;
        int mid = (node_lo + node_hi) / 2;
        return tree[node] = min(
            update(idx, newval, node * 2, node_lo, mid),
            update(idx, newval, node * 2 + 1, mid + 1, node_hi)
        );
    }
public:
    long long query(int lo, int hi) {
        return query(lo, hi, 1, 0, len - 1);
    }

    long long update(int idx, int newval) {
        return update(idx, newval, 1, 0, len - 1);
    }

    RMQ(vector<long long>& arr) {
        len = arr.size();
        tree.resize(len * 4);
        init_tree(arr, 0, len - 1, 1);
    }
};

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        int N, K;
        scanf("%d %d", &N, &K);
        vector<long long> arr;
        for (int i = 0; i < N; ++i) arr.push_back(i);
        vector<long long> negarr;
        for (int n: arr) negarr.push_back(-n);
        RMQ min_q(arr);
        RMQ max_q(negarr);
        for (int i = 0; i < K; ++i) {
            int Q, A, B;
            scanf("%d %d %d", &Q, &A, &B);
            if (Q == 0) {
                long long tmp = arr[A];
                arr[A] = arr[B];
                arr[B] = tmp;
                min_q.update(A, arr[A]);
                min_q.update(B, arr[B]);
                max_q.update(A, -arr[A]);
                max_q.update(B, -arr[B]);
            } else {
                if (min_q.query(A, B) == A && -max_q.query(A, B) == B)
                    printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}
