/*
 * Baekjoon Online Judge #3830
 * https://www.acmicpc.net/problem/3830
 */

#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

int N, M;
vector<int> p;
vector<long long> dist;

int getroot(int u) {
  if (u == p[u])
    return u;
  int parent = getroot(p[u]);
  dist[u] += dist[p[u]];
  return p[u] = parent;
}

void mergesets(int u, int v, long long d) {
  int ru = getroot(u);
  int rv = getroot(v);
  if (ru == rv)
    return;
  p[rv] = ru;
  dist[rv] = d - dist[v] + dist[u];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    cin >> N >> M;
    if (N == 0 && M == 0)
      break;
    p.assign(N + 1, 0);
    iota(p.begin(), p.end(), 0);
    dist.assign(N + 1, 0);

    for (int m = 0; m < M; ++m) {
      char Q;
      int A, B;
      cin >> Q >> A >> B;
      if (Q == '!') {
        long long D;
        cin >> D;
        mergesets(A, B, D);
      } else {
        if (getroot(A) != getroot(B))
          cout << "UNKNOWN\n";
        else
          cout << dist[B] - dist[A] << "\n";
      }
    }
  }

  return 0;
}
