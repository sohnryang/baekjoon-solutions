/*
 * Baekjoon Online Judge #12720
 * https://www.acmicpc.net/problem/12720
 */

#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <numeric>
#include <set>
#include <type_traits>
#include <unordered_map>
#include <vector>

using namespace std;

const long long PRIME_TABLE_LEN = 1'000'001;
bool is_prime[PRIME_TABLE_LEN];
long long A, B, C, P, primes[80000];
vector<long long> parent, r;
set<long long> roots;

long long getroot(long long u) {
  if (u == parent[u])
    return u;
  return parent[u] = getroot(parent[u]);
}

void mergesets(long long u, long long v) {
  u = getroot(u);
  v = getroot(v);
  if (u == v)
    return;
  if (r[u] > r[v])
    swap(u, v);
  parent[u] = v;
  if (r[u] == r[v])
    ++r[v];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  fill(is_prime, is_prime + PRIME_TABLE_LEN, true);
  is_prime[0] = is_prime[1] = false;
  long long prime_count = 0;
  for (long long p = 2; p < PRIME_TABLE_LEN; ++p) {
    if (!is_prime[p])
      continue;
    primes[prime_count++] = p;
    for (long long x = p * p; x < PRIME_TABLE_LEN; x += p)
      is_prime[x] = false;
  }

  cin >> C;
  for (int t = 0; t < C; ++t) {
    cin >> A >> B >> P;
    parent.assign(B - A + 1, 0);
    iota(parent.begin(), parent.end(), 0);
    r.assign(B - A + 1, 1);
    int prime_upper_bound =
        lower_bound(primes, primes + prime_count, B - A + 1) - primes;
    for (int i = 0; i < prime_upper_bound; ++i) {
      if (primes[i] < P)
        continue;
      long long p = primes[i];
      long long root = -1;
      for (long long j = (A / p + (A % p != 0)) * p; j <= B; j += p) {
        if (root == -1) {
          root = j - A;
          continue;
        }
        mergesets(root, j - A);
      }
    }
    roots.clear();
    for (long long i = 0; i <= B - A; ++i)
      roots.insert(getroot(i));
    cout << "Case #" << t + 1 << ": " << roots.size() << "\n";
  }

  return 0;
}
